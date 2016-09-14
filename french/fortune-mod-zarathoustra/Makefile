# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	fortune-mod-zarathoustra
PORTVERSION=	20100905
CATEGORIES=	french
MASTER_SITES=	LOCAL/culot

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Compilation of quotes from Nietzsche's Thus spoke Zarathustra

SUB_FILES=	pkg-message

BUILD_DEPENDS=	fortune_strfile:misc/fortune_strfile
STRCMD=		${LOCALBASE}/bin/fortune_strfile

do-build:
	(cd ${WRKSRC} && ${STRCMD} zarathoustra)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/zarathoustra* \
		${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
