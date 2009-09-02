# New ports collection makefile for:	hs-hat
# Date created:				February 4, 2009
# Whom:					Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hat
PORTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A source-level tracer for Haskell 98

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_GNOME=	glib12

OPTIONS=	GHC   "Build with GHC"   off \
		NHC98 "Build with NHC98" on

.include <bsd.port.pre.mk>

.if !defined(WITH_GHC) && !defined(WITH_NHC98)
IGNORE=	cannot be compiled without a compiler.  Please (re)run 'make config' and choose either GHC or NHC98
.endif

.if defined(WITH_GHC) && defined(WITH_NHC98)
IGNORE= can be compiled only with one of the compilers.  Please (re)run 'make config' and choose either GHC or NHC98
.endif

.if defined(WITH_NHC98) && ${ARCH} == "amd64"
IGNORE= is not supported on AMD64 by NHC98.
.endif

.if defined(WITH_GHC)
IGNORE= is only supported by NHC98.  Please (re)run 'make config' and choose NHC98
.endif

.if ${ARCH} == "i386"
ARCHITECTURE=ix86
.elif ${ARCH} == "amd64"
ARCHITECTURE=amd64
.else
IGNORE= is not supported on your architecture as there is no compiler for it
.endif

PLIST_SUB+=	ARCH=${ARCHITECTURE}

.if defined(WITH_NHC98)
BUILD_DEPENDS+=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
PKGNAMESUFFIX=	-nhc98
.endif

.if defined(WITH_GHC)
BUILD_DEPENDS+=	hs-hmake>=3.0:${PORTSDIR}/devel/hs-hmake \
		ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
PKGNAMESUFFIX=	-ghc
.endif

.if defined(WITH_NHC98)
ALL_TARGET=	hat-nhc
ALL_TARGET+=	hat-lib-nhc
.endif

.if defined(WITH_GHC)
ALL_TARGET=	hat-ghc
ALL_TARGET+=	hat-lib-ghc
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if defined(WITH_NHC98)
PLIST_SUB+=	NHC98=""
PLIST_SUB+=	GHC="@comment "
.endif

.if defined(WITH_GHC)
GHC_VERSION=	6.10.4
PLIST_SUB+=	NHC98="@comment "
PLIST_SUB+=	GHC=""
PLIST_SUB+=	GHC_VER="608"
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION}
.endif

CONFIGURE_ARGS=		--prefix=${PREFIX} --libdir=${PREFIX}/lib

.if defined(WITH_NHC98)
CONFIGURE_ARGS+=	--buildwith=nhc98
.endif

.if defined(WITH_GHC)
CONFIGURE_ARGS+=	--buildwith=ghc
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${DOCSDIR} +docs
PORTDOCS=	*
.endif

MAN1=		black-hat.1 hat-anim.1 hat-cover.1 hat-delta.1 hat-detect.1 hat-nonterm.1 hat-observe.1 \
		hat-stack.1 hat-trail.1 hat-trans.1 pretty-hat.1

pre-everything::
	@${ECHO_CMD} ""
.if defined(WITH_GHC)
	@${ECHO_CMD} " HAT will be built and installed with ghc."
	@${ECHO_CMD} " Define WITH_NHC98 to install with nhc98."
.endif

.if defined(WITH_NHC98)
	@${ECHO_CMD} " HAT will be built and installed with nhc98."
	@${ECHO_CMD} " Define WITH_GHC to install with ghc."
.endif
	@${ECHO_CMD} ""

post-patch:
.if defined(WITH_NHC98)
	@${REINPLACE_CMD} -e "s/-package containers//" ${WRKSRC}/src/tools/Makefile
.endif

post-install:
.if defined(WITH_GHC)
	 @${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.endif
	@${INSTALL_DATA} ${WRKSRC}/src/lib/hat.cabal \
		${PREFIX}/lib/${ARCHITECTURE}-FreeBSD
	@${RM} -rf ${PREFIX}/share/doc/hat/private

.include <bsd.port.post.mk>
