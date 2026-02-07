PORTNAME=	glbsp
PORTVERSION=	2.24
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_src_${PORTVERSION:S/.//}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	BSP node builder for OpenGL-based DOOM engines
WWW=		https://glbsp.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake
MAKEFILE=	Makefile.unx
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-source

PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TRICKS.txt USAGE.txt
PLIST_FILES=	bin/glbsp share/man/man1/glbsp.1.gz include/glbsp.h lib/libglbsp.a

OPTIONS_DEFINE=	DOCS GUI

GUI_DESC=	Build FLTK based GUI
GUI_LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
			libfontconfig.so:x11-fonts/fontconfig \
			libpng.so:graphics/png
GUI_USES=	jpeg xorg
GUI_USE=	XORG=x11,xcursor,xext,xfixes,xft,xinerama,xrender
GUI_ALL_TARGET=	all glBSPX
GUI_PLIST_FILES=	bin/glBSPX

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glbsp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/glbsp.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/src/glbsp.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libglbsp.a ${STAGEDIR}${PREFIX}/lib

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/glBSPX ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
