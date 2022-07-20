PORTNAME=	fotaq
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/scummvm/extras/Flight%20of%20the%20Amazon%20Queen
DISTNAME=	FOTAQ_Talkie-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flight of the Amazon Queen: a classic graphical adventure

RUN_DEPENDS=	scummvm:games/scummvm

LICENSE=	FOTAQ
LICENSE_TEXT=	See ${DOCSDIR}/readme.txt
LICENSE_NAME=	Flight of the Amazon Queen license
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/queen.1c ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
