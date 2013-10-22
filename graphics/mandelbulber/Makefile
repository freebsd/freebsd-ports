# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mandelbulber
DISTVERSION=	1.13-1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	3D Mandelbrot fractal renderer

LICENSE=	GPLv3

USES=		gmake pkgconfig
USE_GNOME=	glib20 gtk20
BUILD_WRKSRC=	${WRKSRC}/makefiles
MAKEFILE=	makefile
CXXFLAGS+=	-DSHARED_DIR=\\\"${DATADIR}\\\"

PLIST_FILES=	bin/${PORTNAME} share/applications/${PORTNAME}.desktop

PORTDOCS=	README NEWS
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/mandelbulber|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}.desktop

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} '*' ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
