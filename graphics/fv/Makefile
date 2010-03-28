# New ports collection makefile for:	fv
# Date created:				07 Sep 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	fv
PORTVERSION=	1.02
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.eaflux.com/fv/sources/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A viewer of hdr/pfm images

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_GL=		glut

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC} \
		&& ${CXX} ${CXXFLAGS} -DNDEBUG -I${WRKSRC} \
		-I${LOCALBASE}/include ${CPPFLAGS} ${PTHREAD_CFLAGS} \
		${LDFLAGS} -L${LOCALBASE}/lib -lpng -lz -lbz2 -lglut \
		-lGLU -lGL -lXi -lXmu -lX11 -lXext -lSM -lm ${PTHREAD_LIBS} \
		-o ${PORTNAME} *.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
