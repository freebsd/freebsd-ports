# New ports collection makefile for:	xkoules
# Date created:				11 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xkoules
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	games/arcade/koules
DISTNAME=	${PORTNAME:S/^x//}${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

.if ${MACHINE_ARCH} == "i386"
PLIST_SUB=	SNDSRV:=""
.else
PLIST_SUB=	SNDSRV:="@comment "
.endif

USE_IMAKE=	yes
MAN6=		xkoules.6

post-extract:
	@${CP} ${WRKSRC}/xkoules.6 ${WRKSRC}/xkoules.man

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ANNOUNCE BUGS Card ChangeLog Koules.FAQ TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
