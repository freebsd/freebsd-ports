# New ports collection makefile for:	nhc98
# Date created:				04 October 2001
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	nhc98
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	lang haskell
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
DISTNAME=	${PORTNAME}src-${PORTVERSION}
DIST_SUBDIR=	nhc98

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-1.16-typesyn \
		patch-1.16-ghc6

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A fully-fledged compiler for Haskell 98

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
BUILD_DEPENDS+=	ghc-5.04.3:${PORTSDIR}/lang/ghc5
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_SIZE=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.if ${OSVERSION} >= 500000
CONFIGURE_ARGS+=	--buildwith=ghc
.endif

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${DOCSDIR} +docs
.endif

MAN1=		harch.1 hmake.1 hp2graph.1 nhc98.1

CONFLICTS=	hs-hmake-*

post-patch:
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile.inc
.for file in Decl FillIn Process
	@${REINPLACE_CMD} -e '/^import PrelBase/d' \
		${WRKSRC}/src/greencard/${file}.lhs
.endfor

post-configure:
	@${ECHO} "LIBDIR=${PREFIX}/lib/nhc98" \
		>> ${WRKSRC}/targets/ix86-FreeBSD/config.cache

post-install:
	${SED} -e "s#/usr/doc/nhc98#${PREFIX}/share/doc/nhc98#" \
	       < ${WRKSRC}/man/nhc98.1 > ${WRKSRC}/man/nhc98.1.fix
	${INSTALL_MAN} ${WRKSRC}/man/nhc98.1.fix ${PREFIX}/man/man1/nhc98.1
	${RM} ${WRKSRC}/man/nhc98.1.fix
.if !defined(NOPORTDOCS)
.for directory in . bugs examples hmake implementation-notes libs
	${RM} -r ${DOCSDIR}/${directory}/CVS
.endfor
.endif

.include <bsd.port.post.mk>
