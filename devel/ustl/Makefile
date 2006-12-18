# ex:ts=8
# Ports collection makefile for:	uSTL
# Date created:			Dec 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ustl
PORTVERSION=	1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	az@FreeBSD.org
COMMENT=	Codespace-frugal STL implementation

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
HAS_CONFIGURE=	yes
MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		INCDIR="${PREFIX}/include" \
		LIBDIR="${PREFIX}/lib"
ALL_TARGET=	# empty

PLIST_FILES=	lib/libustl.so lib/libustl.so.1 lib/libustl.so.1.0.0

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,/bin/bash,/bin/sh," ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|SIZE_MAX|UINT_MAX|" ${WRKSRC}/memblock.h

post-install:
	@${FIND} ${PREFIX}/include/ustl* ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/ustl* -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
