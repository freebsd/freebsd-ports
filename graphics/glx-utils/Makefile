PORTNAME=	glx-utils
DISTVERSIONPREFIX=	${GL_ACCOUNT}-${GL_PROJECT}-
DISTVERSION=	8.4.0-53
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	List GLX capabilities and simple renderer

LICENSE=	MIT

CONFLICTS_INSTALL=	mesa-demos

USES=		gl localbase:ldflags xorg
USE_GITLAB=	yes
USE_GL=		gl
USE_XORG=	x11
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	mesa
GL_PROJECT=	demos
GL_COMMIT=	5435fc7fbd332e171da9a71e33a9b190e9462cf0
WRKSRC_SUBDIR=	src/xdemos
PLIST_FILES=	bin/glxgears \
		bin/glxinfo \
		${NULL}

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o glxinfo glxinfo.c glinfo_common.c ${LDFLAGS} -lGL -lX11)
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o glxgears glxgears.c ${LDFLAGS} -lGL -lX11 -lm)

do-install:
	${INSTALL_PROGRAM} ${PLIST_FILES:Mbin/*:S,^bin,${WRKSRC},} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
