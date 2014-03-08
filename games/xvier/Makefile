# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xvier
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/strategy
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Throw stones into free columns

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		imake
USE_XORG=	x11 xext
MAN6=		xvier.6

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
