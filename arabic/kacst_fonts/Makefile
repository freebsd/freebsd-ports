PORTNAME=	kacst_fonts
PORTVERSION=	2.01
PORTREVISION=	3
CATEGORIES=	arabic
MASTER_SITES=	SF/arabeyes/${PORTNAME} \
		http://www.c-s.li/ports/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Truetype Arabic fonts created by KACST
WWW=	https://www.arabeyes.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		fonts tar:bzip2

NO_BUILD=	yes
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/KacstArabicFonts-${PORTVERSION}

do-install:
	@${MKDIR} ${STAGEDIR}/${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}/${FONTSDIR}

.include <bsd.port.mk>
