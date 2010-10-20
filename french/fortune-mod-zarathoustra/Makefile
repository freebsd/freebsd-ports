# New ports collection makefile for:	fortune-mod-zarathoustra
# Date created:				2010-09-05
# Whom:					Frederic Culot <frederic@culot.org>
#
# $FreeBSD$
#

PORTNAME=	fortune-mod-zarathoustra
PORTVERSION=	20100905
CATEGORIES=	french
MASTER_SITES=	ftp://ftp2.culot.org/culot/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Compilation of quotes from Nietzsche's Thus spoke Zarathustra

SUB_FILES=	pkg-message

STRCMD=		/usr/games/strfile

pre-build:
.if !exists(${STRCMD})
	@${ECHO_MSG} "Please install the games distribution"
	@exit 1
.endif

do-build:
	@cd ${WRKSRC} && ${STRCMD} zarathoustra

do-install:
	@${MKDIR} ${PREFIX}/share/games/fortune
	@${INSTALL_DATA} ${WRKSRC}/zarathoustra* ${PREFIX}/share/games/fortune

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
