PORTNAME=	ae_fonts1_ttf
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	arabic x11-fonts
MASTER_SITES=	SF/arabeyes/Fonts/ae_fonts
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of TrueType Arabic fonts
WWW=		https://www.arabeyes.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/license.txt

USES=		fonts tar:bzip2
FONTNAME=	ae_fonts1

NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=	${WRKDIR}/ae_fonts1-${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*/* ${STAGEDIR}/${FONTSDIR}

.include <bsd.port.mk>
