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
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
BUILD_WRKSRC=	${WRKSRC}/makefiles
MAKEFILE=	makefile
CXXFLAGS+=	-DSHARED_DIR=\\\"${DATADIR}\\\"

PLIST_FILES=	bin/${PORTNAME} share/applications/${PORTNAME}.desktop
PLIST_DIRSTRY=	share/applications

PORTDOCS=	README NEWS
PORTDATA=	*

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/mandelbulber|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}.desktop

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${PREFIX}/share/applications
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/usr/share && ${COPYTREE_SHARE} '*' ${DATADIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
