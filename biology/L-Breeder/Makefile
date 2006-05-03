# ex:ts=8
# New ports collection makefile for:	L-Breeder
# Date created:				30 May 2002
# Whom:					David Yeske <dyeske@yahoo.com> et al
#
# $FreeBSD$
#

PORTNAME=	LBreeder
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	http://www.simonyi.ox.ac.uk/dawkins/software/yan/L-Breeder/
DISTNAME=	${PORTNAME}-source

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Allows you to display and breed L-system forms

LIB_DEPENDS=	wx_gtk2_gl-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24 \
		glut.4:${PORTSDIR}/graphics/libglut

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=	${WRKSRC}/Unix

USE_ZIP=	yes
USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes

WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.4-config

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

 
do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/documentation/* ${DOCSDIR}
.endif
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Lsystems/* ${EXAMPLESDIR}

.include <bsd.port.mk>
