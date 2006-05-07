# New ports collection makefile for:	vvv
# Date created:				10 Sep 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	vvv
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.inf.ufes.br/~thomas/graphics/vvv/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	pav
DISTNAME=	${PORTNAME}_unix
EXTRACT_SUFX=	.tgz

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A tutorial tool for understanding viewing and projection in OpenGL

BUILD_DEPENDS=	${X11BASE}/lib/libglui.a:${PORTSDIR}/devel/glui
LIB_DEPENDS=	glut.4:${PORTSDIR}/graphics/libglut

USE_GMAKE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
MAKE_ENV=	OS=unix X11BASE="${X11BASE}"
ALL_TARGET=	${PORTNAME}

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	vvv.html

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|g\([c+]\)\1|${CXX}|g' \
		${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/glui.h	# we are using glui from the port

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
