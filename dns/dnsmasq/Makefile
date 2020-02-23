# Created by: Steven Honson
# $FreeBSD$

PORTNAME=	dnsmasq
DISTVERSION=	2.80
PORTREVISION=	4	# leave this in even if 0 to avoid PORTEPOCH bumps
PORTEPOCH=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/ \
		LOCAL/mandree/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Lightweight DNS forwarder, DHCP, and TFTP server

LICENSE=	GPLv2

CONFLICTS_INSTALL=dnsmasq-devel-*

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

SUB_FILES=	pkg-message

CFLAGS+=	-Wall -Wno-unused-value -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" COPTS="${CFLAGS}" LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}"

OPTIONS_DEFINE=		IPSET IPV6 DBUS LUA DNSSEC DOCS
OPTIONS_DEFAULT=	DNSSEC IPSET
OPTIONS_EXCLUDE+=	EXAMPLES
OPTIONS_RADIO=		INTL
OPTIONS_RADIO_INTL=	IDN NLS
INTL_DESC=	Internationalization Support Level
NLS_DESC=	IDN+NLS: Int'l Domain Names & National Language support
IDN_DESC=	IDN: Int'l Domain Names WITHOUT full NLS
IPSET_DESC=	Dynamic firewall management of resolved names (needs PF)
LUA_DESC=	Support lease-change scripts written in Lua
DNSSEC_DESC=	Enable DNSSEC caching and validation
USES=		cpe shebangfix tar:xz
SHEBANG_FILES=	contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl \
		contrib/dnslist/dnslist.pl
CPE_VENDOR=	thekelleys

IPV6_CFLAGS_OFF=-DNO_IPV6
IPSET_CFLAGS_OFF=-DNO_IPSET

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext gmake iconv pkgconfig
CFLAGS+=	-DHAVE_LIBIDN2
LIB_DEPENDS+=	libidn2.so:dns/libidn2
PLIST_SUB+=	NLS=""
ALL_TARGET=	all-i18n
_intllibs=	-lidn2 -lintl
.else
_intllibs=
PLIST_SUB+=	NLS="@comment "
.if ${PORT_OPTIONS:MIDN}
USES+=		iconv
CFLAGS+=	-DHAVE_LIBIDN2
LIB_DEPENDS+=	libidn2.so:dns/libidn2
_intllibs+=	-lidn2
.endif
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-1.so:devel/dbus
USES+=		pkgconfig
CPPFLAGS+=	`pkg-config --cflags dbus-1`
CFLAGS+=	-DHAVE_DBUS
LDFLAGS+=	`pkg-config --libs dbus-1`
.endif

.if ${PORT_OPTIONS:MLUA}
CPPFLAGS+=	-I${LUA_INCDIR}
CFLAGS+=	-DHAVE_LUASCRIPT
LDFLAGS+=	-L${LUA_LIBDIR} -llua-${LUA_VER}
USES+=		lua
.endif

.if ${PORT_OPTIONS:MDNSSEC}
CFLAGS+=	-DHAVE_DNSSEC -I${LOCALBASE}/include
USES+=		pkgconfig
LIB_DEPENDS+=	libnettle.so:security/nettle
LIB_DEPENDS+=	libgmp.so:math/gmp
.endif

USE_RC_SUBR=	dnsmasq

.include <bsd.port.pre.mk>

LDFLAGS+=	-L${LOCALBASE}/lib ${_intllibs} ${ICONV_LIB}

pre-configure: pretty-print-config
.if ${PORT_OPTIONS:MIDN}
.if empty(PORT_OPTIONS:MNLS)
	@if ${READELF} -d ${LOCALBASE}/lib/libidn2.so \
		| ${EGREP} -q '\<NEEDED\>.*\[libintl\.so' ; \
	then ${ECHO} ; ${ECHO} 'WARNING: dns/libidn2 was compiled with NLS support!' ; \
	${ECHO} 'Recompile libidn2 WITHOUT_NLS to get rid of NLS dependencies.' ; ${ECHO} ; \
	fi
.else
	@${ECHO} 'WARNING: IDN and NLS enabled, building IDN WITH NLS.'
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${STAGEDIR}${PREFIX}/etc/dnsmasq.conf.sample
	${REINPLACE_CMD} -i '' 's}%%PREFIX%%}${PREFIX}}' ${STAGEDIR}${PREFIX}/etc/dnsmasq.conf.sample
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/trust-anchors.conf ${STAGEDIR}${DATADIR}/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MNLS}
.for i in de es fi fr id it no pl pt_BR ro
	${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/src/${i}.mo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/dynamic-dnsmasq ${STAGEDIR}${EXAMPLESDIR}/dnslist
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl ${STAGEDIR}${EXAMPLESDIR}/dynamic-dnsmasq/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dnslist/dnslist.pl ${STAGEDIR}${EXAMPLESDIR}/dnslist/
	${INSTALL_DATA} ${WRKSRC}/contrib/dnslist/dhcp.css ${STAGEDIR}${EXAMPLESDIR}/dnslist/
	${INSTALL_DATA} ${WRKSRC}/contrib/dnslist/dnslist.tt2 ${STAGEDIR}${EXAMPLESDIR}/dnslist/

.include <bsd.port.post.mk>
