# New ports collection makefile for:	robot
# Date created:         11 October 2003
# Whom:                 Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	robot
PORTVERSION=	4.93.89
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	ftp://lheaftp.gsfc.nasa.gov/pub/corbet/robot/
DISTNAME=	robot-beta

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graph plotting and data analysis program using OpenLook

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	fsplit:${PORTSDIR}/devel/fortran-utils \
		imake:${PORTSDIR}/devel/imake
LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

USE_GMAKE=	yes
MAKE_ENV+=	OPENWINHOME=${LOCALBASE}
WEB_BROWSER?=	firefox
USE_FORTRAN=	yes
FFLAGS+=	-ffixed-line-length-80

MANL=		robot.l

pre-build:
	@${REINPLACE_CMD} -e 's+netscape+${WEB_BROWSER}+ ' \
	  ${WRKSRC}/Robot/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Robot/robot ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/help
	${INSTALL_DATA} ${WRKSRC}/Docs/robot.info ${PREFIX}/lib/help
	${INSTALL_MAN} ${WRKSRC}/Docs/robot.man ${PREFIX}/man/manl/robot.l
.ifndef NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/RobotManual.ps ${DOCSDIR}
	@${GZIP_CMD} ${DOCSDIR}/RobotManual.ps
	@${REINPLACE_CMD} -e 's+/usr/bin+${PREFIX}/bin+ ' \
	  ${WRKSRC}/Demos/*.rob
.endif
.ifndef NOPORTDOCS
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Demos/*.rob ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
