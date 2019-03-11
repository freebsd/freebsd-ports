# $FreeBSD$

PORTNAME=	ayu20
PORTVERSION=	1.7.a
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	OSDN/x-tt/8536/
PKGNAMEPREFIX=	ja-font-
DISTNAME=	ayu20gothic-1.7a

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Ayu 20-dot Kanji font

BUILD_DEPENDS=	mkitalic:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

CONFLICS=	ja-kappa20-[0-9]*

USES=		fonts
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-message
PORTDOCS=	README.txt
MAKEFILE=	${WRKDIR}/Makefile

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install:
	${INSTALL_DATA} ${FILESDIR}/fonts.alias \
	    ${STAGEDIR}${FONTSDIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
