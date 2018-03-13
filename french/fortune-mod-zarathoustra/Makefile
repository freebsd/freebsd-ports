# Created by: Frederic Culot <frederic@culot.org>
# $FreeBSD$

PORTNAME=	fortune-mod-zarathoustra
PORTVERSION=	20100905
CATEGORIES=	french
MASTER_SITES=	LOCAL/culot

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Compilation of quotes from Nietzsche's Thus spoke Zarathustra

LICENSE=	NONE

SUB_FILES=	pkg-message

.if exists(/usr/games/strfile)
STRCMD=		/usr/games/strfile
.elif exists(/usr/bin/strfile)
STRCMD=		/usr/bin/strfile
.else
IGNORE=		needs strfile command. Please install games distribution of base system
.endif

do-build:
	@cd ${WRKSRC} && ${STRCMD} zarathoustra

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune
	${INSTALL_DATA} ${WRKSRC}/zarathoustra* ${STAGEDIR}${PREFIX}/share/games/fortune

.include <bsd.port.mk>
