# New ports collection Makefile for:	xrmftp
# Date created:				28 March 2000
# Whom:					Matt Heckaman <matt@LUCIDA.CA>
#
# $FreeBSD$
#

PORTNAME=	xrmftp
PORTVERSION=	1.2.4
CATEGORIES=	ftp
MASTER_SITES=	http://www.mat.uni.torun.pl/~rafmet/ \
		ftp://ftp.netspring.net/pub/people/rafal-metkowski/
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	matt@LUCIDA.CA

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/xrmftp-1.2.4.src

do-install:
	${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/xrmftp ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/FIXED-BUGS ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${DISTNAME}

.include <bsd.port.mk>
