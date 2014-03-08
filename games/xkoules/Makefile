# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xkoules
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade/koules
DISTNAME=	${PORTNAME:S/^x//}${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast action arcade-style game for X Window

DEPRECATED=	Unmaintained since 2000
EXPIRATION_DATE=	2014-04-11
USES=		imake
USE_XORG=	x11 xext
MAN6=		xkoules.6
MAKE_JOBS_UNSAFE=	yes

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${CP} ${WRKSRC}/xkoules.6 ${WRKSRC}/xkoules.man

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE BUGS Card ChangeLog Koules.FAQ TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
