# Created by: Jochem Kossen <j.kossen@home.nl>
# $FreeBSD$

PORTNAME=	cplay
PORTVERSION=	1.49
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses-based front-end for various audio players

LICENSE=	GPLv2

BROKEN=		Fails to fetch
USES=		gettext gmake python:2

MAKE_ARGS=	PREFIX="${STAGEDIR}${PREFIX}"

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
