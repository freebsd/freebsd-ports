# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	columns
PORTVERSION=	1.2b
PORTREVISION=	6
CATEGORIES=	games
# mastersite disappeared in December 2000
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	thierry
DISTNAME=	Columns-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice little implementation of columns game for X Window System

LICENSE=	GPLv2

USE_SDL=	sdl
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/Columns
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-configure:
	@${REINPLACE_CMD} -e '/chmod 0666/d' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
