# Created by: Oliver Braun <obraun@informatik.unibw-muenchen.de>
# $FreeBSD$

PORTNAME=	nhc98
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	http://haskell.org/${PORTNAME}/
DISTFILES=	${PORTNAME}src-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	nhc98

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Fully-fledged compiler for Haskell 98

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake
# Fails to build with GCC 4.9, cf. PR 196857.
USE_GCC=	4.8

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX} --heap=4M
MAKE_ARGS+=		ARCH=
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		DOCS

DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR} +docs
DOCS_CONFIGURE_OFF=	-docs

PORTDOCS=	*
CONFLICTS=	hs-cpphs-[0-9]*

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile.inc
	@${REINPLACE_CMD} -e 's|$$(CC)|gcc|g' ${WRKSRC}/Makefile

post-configure:
	@${ECHO} "LIBDIR=${PREFIX}/lib/nhc98" \
		>> ${WRKSRC}/targets/ix86-FreeBSD/config.cache

.include <bsd.port.mk>
