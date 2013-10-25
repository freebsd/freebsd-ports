# Created by: Steven Honson
# $FreeBSD$

PORTNAME=	dnsmasq
DISTVERSION=	2.67
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

USE_XZ=		yes
CFLAGS+=	-Wall -Wno-unused-value
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" COPTS="${CFLAGS}" LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}"

OPTIONS_DEFINE=		IPV6 DBUS NLS IDN LUA
OPTIONS_DEFAULT=	IPV6 NLS
OPTIONS_EXCLUDE+=	EXAMPLES
NLS_DESC=	National Language Support (NLS, enables IDN)
IDN_DESC=	International Domain Names (IDN) WITHOUT NLS
LUA_DESC=	Support lease-change scripts in LUA
USES=		shebangfix
SHEBANG_FILES=	contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl \
		contrib/dnslist/dnslist.pl

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIPV6)
CFLAGS+=	-DNO_IPV6
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		pkgconfig gettext
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
PLIST_SUB+=	NLS=""
ALL_TARGET=	all-i18n
USES+=		gmake
.else
PLIST_SUB+=	NLS="@comment "
.if ${PORT_OPTIONS:MIDN}
CFLAGS+=	-DHAVE_IDN
LIB_DEPENDS+=	libidn.so:${PORTSDIR}/dns/libidn
.endif
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-1.so:${PORTSDIR}/devel/dbus
USES+=		pkgconfig
CFLAGS+=	-DHAVE_DBUS
.endif

.if ${PORT_OPTIONS:MLUA}
CFLAGS+=	-DHAVE_LUASCRIPT
USE_LUA=	5.1
.endif

USE_RC_SUBR=	dnsmasq

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s/lua5\.1/lua-5.1/" ${WRKSRC}/Makefile

pre-configure:
	@:
.if ${PORT_OPTIONS:MIDN}
.if empty(PORT_OPTIONS:MNLS)
	@if ${OBJDUMP} -p ${LOCALBASE}/lib/libidn.so \
		| ${EGREP} -q "NEEDED[[:space:]]+lib(intl|iconv)\.so" ; \
	then ${ECHO} ; ${ECHO} 'WARNING: dns/libidn was compiled with NLS support!' ; \
	${ECHO} 'Recompile libidn WITHOUT_NLS to get rid of NLS dependencies.' ; ${ECHO} ; \
	fi
.else
	@${ECHO} 'WARNING: IDN and NLS enabled, building IDN WITH NLS.'
.endif
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
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
