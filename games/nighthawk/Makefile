# New ports collection makefile for:	nighthawk
# Date created:				Apr 4, 2001
# Whom:					Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	nighthawk
PORTVERSION=	3.0.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An X11 shoot-'em up which requires some lateral thinking

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_GL=		glut
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" CPP="${CXX}" CC_FLAGS="${CXXFLAGS}" \
		LIB_FLAGS="${LDFLAGS}"

MAN6=		nighthawk.6

CFLAGS+=	-DINSTALL_DIR=\\\"\${DATADIR}\\\" \
		-DSCORES_FILE=\\\"/var/games/nighthawk.scores\\\" \
		-I${LOCALBASE}/include
LDFLAGS+=	-lm -L${LOCALBASE}/lib -lX11 -lGL -lGLU -lglut

post-patch:
	${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|$$(MAKE)|g ; \
		 s|strip nighthawk||g'
	${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/src/util/mkprotos2.c
	${REINPLACE_CMD} -e 's|^|#|g' ${WRKSRC}/config.user

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nighthawk ${PREFIX}/bin
	${CHOWN} root:games ${PREFIX}/bin/nighthawk
	${CHMOD} g+s ${PREFIX}/bin/nighthawk
	${INSTALL_DATA} ${WRKSRC}/doc/nighthawk.6 ${MANPREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} --exclude ".xvpics" -cf - data | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type f | ${XARGS} ${CHMOD} ${SHAREMODE}
	@${FIND} ${DATADIR} -type d | ${XARGS} ${CHMOD} a+rx
	@${SH} ${PKGINSTALL} ${PORTNAME} POST-INSTALL

.include <bsd.port.mk>
