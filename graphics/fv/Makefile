# New ports collection makefile for:	fv
# Date created:				07 Sep 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	fv
PORTVERSION=	1.01
CATEGORIES=	graphics
MASTER_SITES=	http://www.eaflux.com/fv/sources/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A viewer of hdr/pfm images

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_GCC=	3.3+
USE_GETOPT_LONG=yes
USE_GL=		yes
USE_X_PREFIX=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

do-build:
	${CXX} ${CXXFLAGS} -DNDEBUG -DHAVE_DECL_GETOPT -I${X11BASE}/include \
		-I${LOCALBASE}/include -I${WRKSRC} ${CPPFLAGS} \
		${PTHREAD_CFLAGS} ${LDFLAGS} -L${X11BASE}/lib \
		-L${LOCALBASE}/lib -lpng -lz -lbz2 -lglut -lGLU -lGL -lXi \
		-lXmu -lX11 -lXext -lSM -lm ${PTHREAD_LIBS} \
		-o ${WRKSRC}/${PORTNAME} ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
