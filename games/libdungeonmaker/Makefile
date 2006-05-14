# New ports collection makefile for:    DungeonMaker
# Date created:         08 Nov 2005
# Whom:                 aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libdungeonmaker
PORTVERSION=	2.05
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	dungeonmaker
DISTNAME=	dungeonmaker-${PORTVERSION}

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A program/library that "grows" dungeons for use in isometric games

INSTALLS_SHLIB=	yes
USE_GCC=	3.2+

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
