# Created by: Steven Honson
# $FreeBSD$

PORTNAME=	dnsmasq
DISTVERSION=	2.76
PORTREVISION=	0	# leave this in even if 0 to avoid PORTEPOCH bumps
PORTEPOCH=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/ \
		LOCAL/mandree/

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Lightweight DNS forwarder, DHCP, and TFTP server

LICENSE=	GPLv2

CONFLICTS_INSTALL=dnsmasq-devel-*

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

SUB_FILES=	pkg-message

CFLAGS+=	-Wall -Wno-unused-value -Wno-unused-parameter
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" COPTS="${CFLAGS}" LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}"

OPTIONS_DEFINE=		IPV6 DBUS LUA DNSSEC DOCS
OPTIONS_DEFAULT=	DNSSEC
OPTIONS_EXCLUDE+=	EXAMPLES
OPTIONS_RADIO=		INTL
OPTIONS_RADIO_INTL=	IDN NLS
INTL_DESC=	Internationalization Support Level
NLS_DESC=	IDN+NLS: Int'l Domain Names & National Language support
IDN_DESC=	IDN: Int'l Domain Names WITHOUT full NLS
LUA_DESC=	Support lease-change scripts written in Lua
DNSSEC_DESC=	Enable DNSSEC caching and validation
USES=		cpe shebangfix tar:xz
SHEBANG_FILES=	contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl \
		contrib/dnslist/dnslist.pl
CPE_VENDOR=	thekelleys

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIPV6)
CFLAGS+=	-DNO_IPV6
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext gmake iconv pkgconfig
LIB_DEPENDS+=	libidn.so:dns/libidn
PLIST_SUB+=	NLS=""
ALL_TARGET=	all-i18n
_intllibs=	-lintl
.else
_intllibs=
PLIST_SUB+=	NLS="@comment "
.if ${PORT_OPTIONS:MIDN}
USES+=		iconv
CFLAGS+=	-DHAVE_IDN
LIB_DEPENDS+=	libidn.so:dns/libidn
_intllibs+=	-lidn
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
CFLAGS+=	-DHAVE_DNSSEC
USES+=		pkgconfig
LIB_DEPENDS+=	libnettle.so:security/nettle
LIB_DEPENDS+=	libgmp.so:math/gmp
.endif

USE_RC_SUBR=	dnsmasq

.include <bsd.port.pre.mk>

LDFLAGS+=	-L${LOCALBASE}/lib ${_intllibs} ${ICONV_LIB}

post-patch:
	${REINPLACE_CMD} -e "s/lua5\.1/lua-${LUA_VER}/" ${WRKSRC}/Makefile

pre-configure: pretty-print-config
.if ${PORT_OPTIONS:MIDN}
.if empty(PORT_OPTIONS:MNLS)
	@if ${OBJDUMP} -p ${LOCALBASE}/lib/libidn.so \
		| ${EGREP} -q 'NEEDED[[:space:]]+libintl\.so' ; \
	then ${ECHO} ; ${ECHO} 'WARNING: dns/libidn was compiled with NLS support!' ; \
	${ECHO} 'Recompile libidn WITHOUT_NLS to get rid of NLS dependencies.' ; ${ECHO} ; \
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
