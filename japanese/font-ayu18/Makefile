# $FreeBSD$

PORTNAME=	ayu18
PORTVERSION=	1.3.1.1
PORTREVISION=	2
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	OSDN/x-tt/8535/:goth \
		OSDN/x-tt/8494/:min
PKGNAMEPREFIX=	ja-font-
DISTFILES=	ayu18gothic-1.3a${EXTRACT_SUFX}:goth \
		ayu18mincho-1.1${EXTRACT_SUFX}:min

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Ayu 18-dot Kanji font

BUILD_DEPENDS=	mkitalic:x11-fonts/mkbold-mkitalic \
		bdftopcf:x11-fonts/bdftopcf

USES=		fonts
NO_ARCH=	yes
NO_WRKSUBDIR=	yes
SUB_FILES=	Makefile pkg-message
MAKEFILE=	${WRKDIR}/Makefile
PORTDOCS=	README.txt

OPTIONS_DEFINE=	DOCS

pre-build: apply-slist

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
