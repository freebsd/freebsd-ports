# New ports collection makefile for:	hsql
# Date created:         		2004-01-15
# Whom:					obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hsql
PORTVERSION=	1.0
CATEGORIES=	databases haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	htoolkit
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Haskell access to SQL

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		psql:${PORTSDIR}/databases/postgresql7
RUN_DEPENDS=	${BUILD_DEPENDS}

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
ALL_TARGET=	all docs
.endif

WRKSRC=	${WRKDIR}/HSQL

USE_SIZE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib --enable-postgres
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include/postgresql/server \
		CPPFLAGS=-I${LOCALBASE}/include/postgresql/server
USE_GMAKE=	yes
MAKE_ENV+=	DOCSDIR=${DOCSDIR}

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hsql.pkg ${DATADIR}

.include <bsd.port.mk>
