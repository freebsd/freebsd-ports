# $FreeBSD$

PORTNAME=	open-huninn-font
PORTVERSION=	1.1
CATEGORIES=	chinese x11-fonts
MASTER_SITES=	https://github.com/justfont/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	jf-openhuninn-${DISTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Font based on Kosugi Maru and optimized for common usage in Taiwan

LICENSE=	OFL11

USES=		fonts zip

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${STAGEDIR}${FONTSDIR}
	${LS} ${STAGEDIR}${FONTSDIR}/*.ttf | ${SED} -e's,^${STAGEDIR},,' >> ${TMPPLIST}

.include <bsd.port.mk>
