# New ports collection makefile for:	glui
# Date created:		25 September 2001
# Whom:			mwest@uct.ac.za
#
# $FreeBSD$
#

PORTNAME=	glui
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	devel graphics
MASTER_SITES=	http://www.cs.unc.edu/~rademach/glui/src/release/
DISTNAME=	glui_v2_1_beta

MAINTAINER=	mwest@uct.ac.za
COMMENT=	GLUT-based C++ user interface library

USE_MESA=	yes

USE_GMAKE=	yes
MAKEFILE=	makefile
ALL_TARGET=	# empty
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's:/unc/walk/lib/sgi_irix:${PREFIX}/lib:g; \
		s:/unc/walk/include:${PREFIX}/include:g; \
		s:^CFLAGS:#&:; s:^CC=:CC?=gcc #:; \
		s:^libs =:&${PTHREAD_LIBS}:' ${WRKSRC}/makefile
	@${MKDIR} ${WRKSRC}/lib ${WRKSRC}/bin

do-install:
	${INSTALL_DATA} ${WRKSRC}/glui.h ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/lib/libglui.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/glui
	${INSTALL_DATA} ${WRKSRC}/glui_manual.pdf ${PREFIX}/share/doc/glui
.endif

.include <bsd.port.mk>
