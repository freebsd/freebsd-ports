# Created by: <intron@intron.ac>
# $FreeBSD$

PORTNAME=	fandol
PORTVERSION=	0.3
CATEGORIES=	chinese
MASTER_SITES=	http://mirrors.ctan.org/fonts/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CTAN Fandol: Four GNU GPLv3-licensed Chinese OpenType fonts

LICENSE=	GPLv3

USE_XORG=	x11
USES=		zip fonts
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

FONTNAME=	fandol

SUB_FILES=	pkg-message

PORTDOCS=	README COPYING

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}

	${INSTALL_DATA} ${WRKSRC}/fandol/FandolSong-Bold.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolSong-Regular.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolHei-Regular.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolHei-Bold.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolFang-Regular.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolKai-Regular.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolBraille-Display.otf \
		${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/fandol/FandolBraille-Regular.otf \
		${STAGEDIR}${FONTSDIR}

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/fandol/README \
		${WRKSRC}/fandol/COPYING \
			${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
