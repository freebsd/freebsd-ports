# New ports collection makefile for:	hat
# Date created:				16 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	hat
PORTVERSION=	2.04
CATEGORIES=	devel haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A source-level tracer for Haskell 98

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOME=	glib12

OPTIONS=	NHC98 "Build with nhc98" off

.include <bsd.port.pre.mk>

.if defined(WITH_NHC98) && ${OSVERSION} >= 500000
BROKEN=	"does not build with nhc98 on this platform"
.endif

.if defined(WITH_NHC98)
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
PKGNAMESUFFIX=	-nhc98
.else
BUILD_DEPENDS=	hmake:${PORTSDIR}/devel/hs-hmake \
		ghc-6.4:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc-6.4:${PORTSDIR}/lang/ghc
PKGNAMESUFFIX=	-ghc6
.endif

ALL_TARGET=	hat
.if defined(WITH_NHC98)
ALL_TARGET+=	hat-lib-nhc
.else
ALL_TARGET+=	hat-lib-ghc
.endif

.if defined(WITH_NHC98)
PLIST_SUB+=	NHC98=""
PLIST_SUB+=	GHC="@comment "
.else
PLIST_SUB+=	NHC98="@comment "
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC=""
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"
.endif

CONFIGURE_ARGS=		--prefix=${PREFIX} --libdir=${PREFIX}/lib
.if defined(WITH_NHC98)
CONFIGURE_ARGS+=	--buildwith=nhc98
.else
CONFIGURE_ARGS+=	--buildwith=ghc
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${DOCSDIR} +docs
PORTDOCS=	*
.endif

MAN1=		hat-cover.1 hat-detect.1 hat-nonterm.1 hat-observe.1 \
		hat-stack.1 hat-trail.1 hat-trans.1

pre-everything::
	@${ECHO_CMD} ""
.if !defined(WITH_NHC98)
	@${ECHO_CMD} " HAT will be built and installed with ghc."
	@${ECHO_CMD} " Define WITH_NHC98 to install with nhc98."
.else
	@${ECHO_CMD} " HAT will be built and installed with nhc98."
.endif
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e "s|glib-config|${GLIB_CONFIG}|" \
		${WRKSRC}/configure ${WRKSRC}/src/hattools/Makefile
.if !(defined(WITH_NHC98))
.for f in hattrans/Makefile hatlib/Makefile
	@${REINPLACE_CMD} -e "s/package lang/package lang -package haskell98/" ${WRKSRC}/src/${f}
.endfor
	@${REINPLACE_CMD} -e "s/package lang/package lang -package base -package haskell98/" ${WRKSRC}/src/hattools/Makefile
.endif

post-install:
.	for i in Foreign/C NHC System/Directory Text/Html Text/Regex Text/Show
	  @${RMDIR} ${LOCALBASE}/include/hat/${i} # empty!
.	endfor
.	if !defined(WITH_NHC98)
	  @${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.	endif

	@${INSTALL_DATA} ${WRKSRC}/src/hatlib/hat.cabal \
		${PREFIX}/lib/ix86-FreeBSD
	@${RM} -rf ${PREFIX}/share/doc/hat/CVS

.include <bsd.port.post.mk>
