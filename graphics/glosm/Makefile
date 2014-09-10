# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glosm
PORTVERSION=	0.0.2
PORTREVISION=	3
CATEGORIES=	graphics geography
MASTER_SITES=	http://cloud.github.com/downloads/AMDmi3/glosm/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D OpenGL renderer for OpenStreetMap

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libexpat.so:${PORTSDIR}/textproc/expat2

USES=		tar:bzip2 cmake
USE_GL=		gl
USE_SDL=	sdl

PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	DOCS

regression-test:
	cd ${BUILD_WRKSRC} && ctest

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
