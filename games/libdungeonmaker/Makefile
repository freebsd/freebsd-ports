# New ports collection makefile for:    DungeonMaker
# Date created:         08 Nov 2005
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libdungeonmaker
PORTVERSION=	2.05
CATEGORIES=	games devel
MASTER_SITES=	SF/dungeonmaker/dungeonmaker/${PORTVERSION}
DISTNAME=	dungeonmaker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program/library that "grows" dungeons for use in isometric games

USE_LDCONFIG=	yes

SUB_FILES=	pkg-message
PLIST_SUB+=	HAS_DOCS=${HAS_DOCS}

post-extract:
	@${CP} ${WRKSRC}/Makefile.bsd ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/DM2_Manual/* ${DOCSDIR}

	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/design* ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/main.cpp ${EXAMPLESDIR}

	@${CAT} ${PKGMESSAGE}
HAS_DOCS=""
.else
HAS_DOCS="@comment "
.endif

.include <bsd.port.mk>
