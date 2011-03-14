# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	2.57
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/ \
		${MASTER_SITE_LOCAL}/
MASTER_SITE_SUBDIR=	mandree
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Lightweight DNS forwarder, DHCP and TFTP server

LICENSE=	GPLv2
USE_XZ=		yes

MAN8=		dnsmasq.8

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

SUB_FILES=	pkg-message

MAKE_JOBS_SAFE=	yes
MAKE_ENV=	LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}" COPTS="${CFLAGS}"
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

OPTIONS=	IPV6 "IPv6 support" on
OPTIONS+=	DBUS "DBUS support" off
OPTIONS+=	NLS  "National Language Support (NLS, enables IDN)" on
OPTIONS+=	IDN  "International Domain Names (IDN) WITHOUT NLS" off
# unfortunately, NLS always enables IDN in dnsmasq 2.57

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPV6)
CFLAGS+=	-DNO_IPV6
.endif

.if !defined(WITHOUT_NLS)
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
PLIST_SUB+=	NLS=""
ALL_TARGET=	all-i18n
USE_GETTEXT=	yes
USE_GMAKE=	yes
.else
PLIST_SUB+=	NLS="@comment "
.if defined(WITH_IDN)
MAKE_ARGS+=	COPTS=-DHAVE_IDN
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
.endif
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
CFLAGS+=	-DHAVE_DBUS
.endif

USE_RC_SUBR=	dnsmasq.sh

pre-configure:
	@:
.if defined(WITH_IDN)
.if defined(WITHOUT_NLS)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(WITHOUT_NLS)
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
