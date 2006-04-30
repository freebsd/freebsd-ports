# Ports collection Makefile for:	dualserver
# Date created:				10 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=	dualserver
PORTVERSION=	2.0
CATEGORIES=	dns net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dhcp-dns-server
DISTNAME=	${PORTNAME}V${PORTVERSION}

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	Combined DHCP/DNS server for small LANs

USE_RC_SUBR=	dualserver.sh
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	sbin/dualserver etc/dualserver.conf.sample

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-dualserver.h \
		${FILESDIR}/extra-patch-dualserver.cpp
.endif

pre-patch:
	${REINPLACE_CMD} 's/[[:cntrl:]]*$$//' ${WRKSRC}/*
	${REINPLACE_CMD} 's|/etc/dualserver.ini|${PREFIX}/etc/dualserver.conf|' ${WRKSRC}/dualserver.cpp
	${REINPLACE_CMD} 's|/etc/dualserver.state|/var/run/dualserver.state|' ${WRKSRC}/dualserver.cpp

do-build:
	${CXX} -o ${WRKSRC}/dualserver ${WRKSRC}/dualserver.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dualserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dualserver.ini ${PREFIX}/etc/dualserver.conf.sample

.include <bsd.port.post.mk>
