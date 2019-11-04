# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	game
DISTVERSION=	1.9.6
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Module designed to write games in Python

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/docs/LGPL

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libsmpeg.so:multimedia/smpeg
RUN_DEPENDS=	${PYNUMPY} \
		v4l_compat>0:multimedia/v4l_compat

USES=		jpeg python sdl xorg
USE_SDL=	ttf image mixer
USE_PYTHON=	autoplist distutils
USE_XORG=	x11

SDLNOX11=	sdl-nox11-[0-9]*

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}

#Remove Un-needed macosx files
	@${RM} -r ${WRKSRC}/examples/macosx
	${TAR} -C ${WRKSRC}/examples -cf - . | \
		${TAR} --unlink -C ${STAGEDIR}${EXAMPLESDIR} -xf -

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | \
	${TAR} --unlink -C ${STAGEDIR}${DOCSDIR} -xf -

.include <bsd.port.mk>
