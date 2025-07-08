PORTNAME=	dnsmasq
DISTVERSION=	2.92test16 # remember to bump PORTEPOCH when going from test to rc!
# Leave the PORTREVISION in even if 0 to avoid accidental PORTEPOCH bumps:
PORTREVISION=	0
PORTEPOCH=	6
CATEGORIES=	dns
#MASTER_SITES=	LOCAL/mandree/ \
#		https://www.thekelleys.org.uk/dnsmasq/release-candidates/
MASTER_SITES=	LOCAL/mandree/ \
		https://www.thekelleys.org.uk/dnsmasq/test-releases/
PKGNAMESUFFIX=	-devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Lightweight DNS forwarder, DHCP, and TFTP server
WWW=		https://www.thekelleys.org.uk/dnsmasq/doc.html

LICENSE=	GPLv2

DEPRECATED=	Short-lived test branch, to be removed after v2.92 release

USES=		cpe shebangfix tar:xz
CPE_VENDOR=	thekelleys

SHEBANG_FILES=	contrib/dnslist/dnslist.pl \
		contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		COPTS="${CFLAGS}" \
		LIBS="${LDFLAGS}" \
		PREFIX="${PREFIX}" \
		RPM_OPT_FLAGS="${CPPFLAGS}"
CFLAGS+=	-Wall -Wno-unused-function -Wno-unused-parameter \
		-Wno-unused-value -Wno-unused-variable
CPPFLAGS+=	-I${LOCALBASE}/include

CONFLICTS_INSTALL=	dnsmasq-2*

SUB_FILES=	pkg-message

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

OPTIONS_DEFINE=		DBUS DNSSEC DOCS IPSET IPV6 LUA
OPTIONS_DEFAULT=	DNSSEC IPSET
OPTIONS_RADIO=		INTL
OPTIONS_RADIO_INTL=	IDN NLS
OPTIONS_EXCLUDE+=	EXAMPLES

DNSSEC_DESC=	Enable DNSSEC caching and validation (needs nettle)
IDN_DESC=	IDN: Int'l Domain Names WITHOUT full NLS
INTL_DESC=	Internationalization Support Level
IPSET_DESC=	Dynamic firewall management of resolved names (needs PF)
LUA_DESC=	Support lease-change scripts written in Lua
NLS_DESC=	IDN+NLS: Int'l Domain Names & National Language support

IPSET_CFLAGS_OFF=	-DNO_IPSET
IPV6_CFLAGS_OFF=	-DNO_IPV6

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
USES+=		lua pkgconfig
.endif

.if ${PORT_OPTIONS:MDNSSEC}
CFLAGS+=	-DHAVE_DNSSEC -I${LOCALBASE}/include
USES+=		pkgconfig
LIB_DEPENDS+=	libgmp.so:math/gmp \
		libnettle.so:security/nettle
.endif

USE_RC_SUBR=	dnsmasq

.include <bsd.port.pre.mk>

LDFLAGS+=	-L${LOCALBASE}/lib ${_intllibs} ${ICONV_LIB}

post-patch:
	${REINPLACE_CMD} -e '/^LUA /s/lua/lua-${LUA_VER}/' ${WRKSRC}/Makefile

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
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8
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
