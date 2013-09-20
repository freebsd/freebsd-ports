# Created by: Gabor Pali <pgj@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hat
PORTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	devel haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Source-level tracer for Haskell 98

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_GNOME=	glib12

OPTIONS_SINGLE=	SG1
OPTIONS_SINGLE_SG1=	GHC NHC98
GHC_DESC=	GHC support
NHC98_DESC=	NHC98 support

OPTIONS_DEFAULT=	NHC98

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNHC98} && ${ARCH} == "amd64"
IGNORE= is not supported on AMD64 by NHC98.
.endif

.if ${PORT_OPTIONS:MGHC}
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

.if ${PORT_OPTIONS:MNHC98}
BUILD_DEPENDS+=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
PKGNAMESUFFIX=	-nhc98
.endif

.if ${PORT_OPTIONS:MGHC}
BUILD_DEPENDS+=	hs-hmake>=3.0:${PORTSDIR}/devel/hs-hmake \
		ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
PKGNAMESUFFIX=	-ghc
.endif

.if ${PORT_OPTIONS:MNHC98}
ALL_TARGET=	hat-nhc
ALL_TARGET+=	hat-lib-nhc
.endif

.if ${PORT_OPTIONS:MGHC}
ALL_TARGET=	hat-ghc
ALL_TARGET+=	hat-lib-ghc
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.if ${PORT_OPTIONS:MNHC98}
PLIST_SUB+=	NHC98=""
PLIST_SUB+=	GHC="@comment "
.endif

.if ${PORT_OPTIONS:MGHC}
GHC_VERSION=	6.10.4
PLIST_SUB+=	NHC98="@comment "
PLIST_SUB+=	GHC=""
PLIST_SUB+=	GHC_VER="608"
PLIST_SUB+=	GHC_VERSION=${GHC_VERSION}
.endif

CONFIGURE_ARGS=		--prefix=${PREFIX} --libdir=${PREFIX}/lib

.if ${PORT_OPTIONS:MNHC98}
CONFIGURE_ARGS+=	--buildwith=nhc98
.endif

.if ${PORT_OPTIONS:MGHC}
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
.if ${PORT_OPTIONS:MGHC}
	@${ECHO_CMD} " HAT will be built and installed with ghc."
	@${ECHO_CMD} " Define NHC98 to install with nhc98."
.endif

.if ${PORT_OPTIONS:MNHC98}
	@${ECHO_CMD} " HAT will be built and installed with nhc98."
	@${ECHO_CMD} " Define GHC to install with ghc."
.endif
	@${ECHO_CMD} ""

post-patch:
.if ${PORT_OPTIONS:MNHC98}
	@${REINPLACE_CMD} -e "s/-package containers//" ${WRKSRC}/src/tools/Makefile
.endif

post-install:
.if ${PORT_OPTIONS:MGHC}
	 @${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.endif
	@${INSTALL_DATA} ${WRKSRC}/src/lib/hat.cabal \
		${PREFIX}/lib/${ARCHITECTURE}-FreeBSD
	@${RM} -rf ${PREFIX}/share/doc/hat/private

.include <bsd.port.mk>
