# New ports collection makefile for:	hsql
# Date created:         		2004-01-15
# Whom:					obraun@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	hsql
PORTVERSION=	1.2
CATEGORIES=	databases haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	htoolkit
PKGNAMEPREFIX=	hs-
DISTNAME=	HSQL-${PORTVERSION}

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	Haskell access to SQL

BUILD_DEPENDS=	psql:${PORTSDIR}/databases/postgresql7 \
		ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	psql:${PORTSDIR}/databases/postgresql7 \
		ghc:${PORTSDIR}/lang/ghc

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
ALL_TARGET=	all docs
.endif

WRKSRC=	${WRKDIR}/HSQL
USE_SIZE=	yes
USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib --enable-postgres
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include/postgresql/server \
		CPPFLAGS=-I${LOCALBASE}/include/postgresql/server
USE_GMAKE=	yes
MAKE_ENV+=	DOCSDIR=${DOCSDIR}

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/hugs)
WITH_HUGS=	yes
.endif

.if defined(PACKAGE_BUILDING)
WITH_HUGS=	yes
.endif

.if defined(WITH_HUGS)
BUILD_DEPENDS+=	hugs:${PORTSDIR}/lang/hugs
RUN_DEPENDS+=	hugs:${PORTSDIR}/lang/hugs
.endif

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

.if defined(WITH_HUGS)
PLIST_SUB+=	HUGS=""
.else
PLIST_SUB+=	HUGS="@comment "
.endif

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} " HSQL will be installed for ghc."
	@${ECHO_CMD} ""
.if defined(WITH_HUGS)
	@${ECHO_CMD} " HSQL will be installed for hugs."
.else
	@${ECHO_CMD} " Define WITH_HUGS to install HSQL for hugs."
.endif
	@${ECHO_CMD} ""

post-install:
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hsql.pkg ${DATADIR}

.include <bsd.port.post.mk>
