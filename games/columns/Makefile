# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	columns
PORTVERSION=	1.2b
PORTREVISION=	9
CATEGORIES=	games
# mastersite disappeared in December 2000
MASTER_SITES=	LOCAL/thierry \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	Columns-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nice little implementation of columns game for X Window System

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

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
	@${MKDIR} ${STAGEDIR}/var/games
	${MV} ${STAGEDIR}${DATADIR}/columns.hsc ${STAGEDIR}/var/games/columns.hsc.sample

.include <bsd.port.mk>
