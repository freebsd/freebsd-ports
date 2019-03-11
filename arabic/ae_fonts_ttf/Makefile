# Created by: Samy Al Bahra <samy@kerneled.com>
# $FreeBSD$

PORTNAME=	ae_fonts1_ttf
PORTVERSION=	1.1
PORTREVISION=	5
CATEGORIES=	arabic x11-fonts
MASTER_SITES=	SF/arabeyes/Fonts/ae_fonts
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of TrueType Arabic fonts

LICENSE=	GPLv2

USES=		fonts tar:bzip2
WRKSRC=		${WRKDIR}/ae_fonts1-${PORTVERSION}
SUB_FILES=	pkg-message
NO_BUILD=	yes

FONTNAME=	ae_fonts1

do-install:
	@${MKDIR} ${STAGEDIR}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*/* ${STAGEDIR}/${FONTSDIR}

.include <bsd.port.mk>
