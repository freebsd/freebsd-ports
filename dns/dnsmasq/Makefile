# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	2.49
PORTREVISION=	2
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	Lightweight DNS forwarder, DHCP and TFTP server

MAN8=		dnsmasq.8

PORTDOCS=	CHANGELOG CHANGELOG.archive FAQ doc.html setup.html

RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

USE_GNOME=	pkgconfig
MAKE_JOBS_SAFE=	yes
MAKE_ENV=	LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}" COPTS="${CFLAGS}"
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" PREFIX="${PREFIX}"

OPTIONS=	IPV6 "IPv6 support" on
OPTIONS+=	DBUS "DBUS support" off

.include <bsd.port.pre.mk>

.if defined(WITHOUT_IPV6)
CFLAGS+=	-DNO_IPV6
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-1:${PORTSDIR}/devel/dbus
CFLAGS+=	-DHAVE_DBUS
.endif

USE_RC_SUBR=	dnsmasq.sh

post-patch:
.if ${OSVERSION} < 700000 && defined(WITH_DBUS)
	@${REINPLACE_CMD} -e 's|DBUS_LIBS="|DBUS_LIBS="${PTHREAD_LIBS} |' ${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.8 ${PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	${MKDIR} ${EXAMPLESDIR}/dynamic-dnsmasq ${EXAMPLESDIR}/dnslist
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dynamic-dnsmasq/dynamic-dnsmasq.pl ${EXAMPLESDIR}/dynamic-dnsmasq/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dnslist/dnslist.pl ${EXAMPLESDIR}/dnslist/
	${INSTALL_DATA} ${WRKSRC}/contrib/dnslist/dhcp.css ${EXAMPLESDIR}/dnslist/
	${INSTALL_DATA} ${WRKSRC}/contrib/dnslist/dnslist.tt2 ${EXAMPLESDIR}/dnslist/

.include <bsd.port.post.mk>
