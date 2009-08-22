# New ports collection makefile for:	premake
# Date created:		2004-03-25
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	premake
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/Premake/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	lippe@FreeBSD.org
COMMENT=	Writes build scripts

WRKSRC=		${WRKDIR}/Premake-${PORTVERSION}

USE_DOS2UNIX=	yes
USE_ZIP=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/premake

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/premake ${PREFIX}/bin

.include <bsd.port.post.mk>
