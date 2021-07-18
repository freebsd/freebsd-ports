# Created by: issei <issei@jp.FreeBSD.org>

PORTNAME=	xchadance
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.mk.bsdclub.org/pub/FreeBSD/distfiles/ \
		LOCAL/nyan
DISTFILES=	xchada01.lzh

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display a dancing girl "ChaCha."

# Converted from RESTRICTED
LICENSE=	xchadance
LICENSE_NAME=	xchadance
LICENSE_TEXT=	'contains commercial character data'
LICENSE_PERMS=	auto-accept

USES=		lha xorg
USE_XORG=	x11
MAKEFILE=	makefile
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@(cd ${WRKSRC}; \
		${PATCH} < ${WRKSRC}/xchada01.bug)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.jp ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.eng ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
