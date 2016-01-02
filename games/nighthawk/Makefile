# Created by: Mark Pulford <mark@kyne.com.au>
# $FreeBSD$

PORTNAME=	nighthawk
PORTVERSION=	3.0.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 shoot-'em up which requires some lateral thinking

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake localbase tar:bzip2
USE_GL=		glut
MAKE_ARGS=	CC="${CC}" CPP="${CXX}" CC_FLAGS="${CXXFLAGS}" \
		LIB_FLAGS="${LDFLAGS}" GCC="${CC}" CFLAGS="${CFLAGS}"

CFLAGS+=	-DINSTALL_DIR=\\\"\${DATADIR}\\\" \
		-DSCORES_FILE=\\\"/var/games/nighthawk.scores\\\"
LDFLAGS+=	-lm -lX11 -lGL -lGLU -lglut

post-patch:
	${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|$$(MAKE)|g ; \
		 s|strip nighthawk||g'
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/src/util/mkprotos2.c
	${REINPLACE_CMD} -e 's|^|#|g' ${WRKSRC}/config.user

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_PROGRAM} nighthawk \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/doc &&  ${INSTALL_MAN} nighthawk.6 \
		${STAGEDIR}${MANPREFIX}/man/man6)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TAR} -C ${WRKSRC} --exclude ".xvpics" -cf - data | \
		${TAR} -C ${STAGEDIR}${DATADIR} --unlink -xf -

.include <bsd.port.mk>
