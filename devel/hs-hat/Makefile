# New ports collection makefile for:	hat
# Date created:				16 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	hat
PORTVERSION=	2.00
CATEGORIES=	devel haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

.if defined(WITHOUT_NHC98)
BROKEN=	does not build with ghc-5.04 for the time being
.endif

.if defined(WITH_GHC)
.undef WITH_GHC
.endif

.if !defined(WITHOUT_NHC98)
BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.else
WITH_GHC=	yes
BUILD_DEPENDS+= hmake:${PORTSDIR}/devel/hs-hmake
.endif
.if defined(WITH_GHC)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BROKEN=	does not build with gcc3x
.endif

.if !defined(WITH_GHC) || defined(WITHOUT_NHC98)
ALL_TARGET=	hat
.endif
.if !defined(WITHOUT_NHC98)
PLIST_SUB+=	NHC98=""
.else
PLIST_SUB+=	NHC98="@comment "
.endif
.if defined(WITH_GHC)
PLIST_SUB+=	GHC=""
.else
PLIST_SUB+=	GHC="@comment "
.endif

CONFIGURE_ARGS=		--prefix=${PREFIX} --libdir=${PREFIX}/lib
.if !defined(WITHOUT_NHC98)
CONFIGURE_ARGS+=	--buildwith=nhc98
.else
CONFIGURE_ARGS+=	--buildwith=ghc
.endif
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc +docs
.endif

MAN1=		hat-detect.1 hat-observe.1 hat-stack.1 hat-trail.1

pre-everything::
	@${ECHO_CMD} ""
.if defined(WITH_GHC) && !defined(WITHOUT_NHC98)
	@${ECHO_CMD} " HAT will be built and installed for both nhc98 and ghc."
.elif defined(WITHOUT_NHC98)
	@${ECHO_CMD} " HAT will be built and installed for ghc only."
.else
	@${ECHO_CMD} " HAT will be built and installed for nhc98 only."
#	@${ECHO_CMD} " Define WITH_GHC      to install for ghc, too."
#	@${ECHO_CMD} " Define WITHOUT_NHC98 to install for ghc only."
	@${ECHO_CMD} " HAT does not build with ghc-5.04 for the time being."
.endif
	@${ECHO_CMD} ""

post-patch:
	@${REINPLACE_CMD} -e "s|glib-config|${GLIB_CONFIG}|" \
		${WRKSRC}/configure ${WRKSRC}/src/hat/tools/Makefile \
		${WRKSRC}/src/hat/oldtools/Makefile

.if !defined(NOPORTDOCS)
post-install:
	@${RM} -r ${PREFIX}/share/doc/hat/CVS
.for ending in aux log
	@${RM} ${PREFIX}/share/doc/hat/tutorial1.${ending}
.endfor
.for ending in aux log out toc
	@${RM} ${PREFIX}/share/doc/hat/hatuser.${ending}
.endfor
.endif

.include <bsd.port.post.mk>
