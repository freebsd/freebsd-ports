# New ports collection makefile for:	hat
# Date created:				16 June 2002
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	hat
PORTVERSION=	2.00
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/

MAINTAINER=	obraun@informatik.unibw-muenchen.de

BUILD_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
RUN_DEPENDS=	nhc98:${PORTSDIR}/lang/nhc98
.if defined(WITH_GHC)
BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc
.endif

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GLIB=	yes
.if defined(WITH_GHC)
PLIST_SUB=	GHC=""
.else
ALL_TARGET=	hat
PLIST_SUB=	GHC="@comment "
.endif

CONFIGURE_ARGS=		--prefix=${PREFIX}
CONFIGURE_ARGS+=	--buildwith=nhc98 --libdir=${PREFIX}/lib
.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc +docs
.endif

MAN1=		hat-detect.1 hat-observe.1 hat-stack.1 hat-trail.1

pre-everything::
	@${ECHO_CMD} ""
.if defined(WITH_GHC)
	@${ECHO_CMD} " HAT will build and install for both nhc98 and ghc."
.else
	@${ECHO_CMD} " HAT will build and install for nhc98 only."
	@${ECHO_CMD} " Define WITH_GHC to install for ghc, too."
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

.include <bsd.port.mk>
