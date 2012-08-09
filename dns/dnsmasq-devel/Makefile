# New ports collection makefile for:	dnsmasq
# Date created:				2012-08-07
# Whom:					Matthias Andree
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
DISTVERSION=	2.63rc3
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/release-candidates/
PKGNAMESUFFIX=	-devel

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Lightweight DNS forwarder, DHCP, and TFTP server

LICENSE=	GPLv2

NO_PACKAGE=	Package stable version instead

CONFLICTS_INSTALL=dnsmasq-2*

MAN8=		dnsmasq.8

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

SUB_FILES=	pkg-message

USE_XZ=		yes
MAKE_JOBS_SAFE=	yes
CFLAGS+=	-Wall -Wno-unused-value
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}" COPTS="${CFLAGS}" LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}"

OPTIONS_DEFINE=		IPV6 DBUS NLS IDN LUA
OPTIONS_DEFAULT=	IPV6 NLS
OPTIONS_EXCLUDE+=	EXAMPLES
NLS_DESC=	National Language Support (NLS, enables IDN)
IDN_DESC=	International Domain Names (IDN) WITHOUT NLS
LUA_DESC=	Support lease-change scripts in LUA

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MIPV6)
CFLAGS+=	-DNO_IPV6
.endif

.if ${PORT_OPTIONS:MNLS}
USE_PKGCONFIG=	yes
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
PLIST_SUB+=	NLS=""
ALL_TARGET=	all-i18n
USE_GETTEXT=	yes
USE_GMAKE=	yes
.else
PLIST_SUB+=	NLS="@comment "
.if ${PORT_OPTIONS:MIDN}
CFLAGS+=	-DHAVE_IDN
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
.endif
.endif

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
USE_PKGCONFIG=	yes
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
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 ${PREFIX}/man/man8
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MNLS}
.for i in de es fi fr id it no pl pt_BR ro
	${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/src/${i}.mo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/${PORTNAME}.mo
.endfor
.endif
	${MKDIR} ${EXAMPLESDIR}/dynamic-dnsmasq ${EXAMPLESDIR}/dnslist
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl ${EXAMPLESDIR}/dynamic-dnsmasq/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dnslist/dnslist.pl ${EXAMPLESDIR}/dnslist/
	${INSTALL_DATA} ${WRKSRC}/contrib/dnslist/dhcp.css ${EXAMPLESDIR}/dnslist/
	${INSTALL_DATA} ${WRKSRC}/contrib/dnslist/dnslist.tt2 ${EXAMPLESDIR}/dnslist/
	if [ ! -f ${PREFIX}/etc/dnsmasq.conf ]; then \
		${CP} -p ${PREFIX}/etc/dnsmasq.conf.example ${PREFIX}/etc/dnsmasq.conf; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
