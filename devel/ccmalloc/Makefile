# New ports collection makefile for:	oaf
# Date created:				1st June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ccmalloc
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.inf.ethz.ch/personal/biere/projects/ccmalloc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ memory profiler and memory leak tracer

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}

SUB_FILES=	pkg-message
PLIST_SUB=	CXX="${CXX}"

.include <bsd.port.pre.mk>

.if ${CC} != "cc" || ${CXX} != "c++"
BROKEN=		Does not build with CC or CXX set
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=".*"|CFLAGS="${CFLAGS}"|; \
		s|CXXFLAGS=".*"|CXXFLAGS="${CXXFLAGS}"|' ${WRKSRC}/configure
.if ${OSVERSION} >= 500000
	@${REINPLACE_CMD} -e '/prefix=/ s|expr $$1|expr -- $$1|' \
		${WRKSRC}/configure
.endif
	@${REINPLACE_CMD} -e 's|-ldl||' ${WRKSRC}/src/ccmalloc.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
