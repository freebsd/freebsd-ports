# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	2.55
PORTEPOCH=	1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/ \
		http://homepages.uni-paderborn.de/mandree/
EXTRACT_SUFX=	.tar.lzma

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Lightweight DNS forwarder, DHCP and TFTP server

USE_XZ=		yes

MAN8=		dnsmasq.8

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

SUB_FILES=	pkg-message

MAKE_JOBS_SAFE=	yes
MAKE_ENV=	LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}" COPTS="${CFLAGS}"
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

OPTIONS=	IPV6 "IPv6 support" on
OPTIONS+=	DBUS "DBUS support" off
OPTIONS+=	NLS  "NLS and IDN support" on
# unfortunately, NLS and IDN are inseparable in dnsmasq 2.51rc1, this
# has been reported to Simon Kelley on 2009-10-01 by the port maintainer.

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
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
CFLAGS+=	-DHAVE_DBUS
.if ${OSVERSION} < 700000
LDFLAGS+=	${PTHREAD_LIBS}
.endif
.endif

USE_RC_SUBR=	dnsmasq.sh

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
