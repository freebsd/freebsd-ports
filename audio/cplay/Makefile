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

USES=		gettext gmake
USE_PYTHON=	yes

MAKE_ARGS=	PREFIX="${PREFIX}"

MAN1=		cplay.1
PORTDOCS=	README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
