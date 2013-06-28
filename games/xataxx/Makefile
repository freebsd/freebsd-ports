# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xataxx
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/../R5contrib
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strategy game of position and movement for X Window System

OPTIONS_DEFINE=	DOCS

USES=		imake
USE_XORG=	x11 xext
MAKE_JOBS_SAFE=	yes

MAN6=		xataxx.6

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in README TODO
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
