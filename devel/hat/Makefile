# New ports collection makefile for:	nhc98
# Date created:				04 October 2001
# Whom:					Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$

PORTNAME=	nhc98
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/haskell/${PORTNAME}/
DISTNAME=	${PORTNAME}src-${PORTVERSION}
DIST_SUBDIR=	nhc98

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-1.10-IO \
		patch-1.10-arrow \
		patch-1.10-blockbuffer \
		patch-1.10-commas \
		patch-1.10-counter \
		patch-1.10-hp2graph \
		patch-1.10-keywords \
		patch-1.10-lhs \
		patch-1.10-patterns \
		patch-1.10-hiding \
		patch-1.10-ghc5.02

MAINTAINER=	obraun@informatik.unibw-muenchen.de

.if defined(WITH_TRACER)
RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk
BUILD_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.if !defined(WITH_TRACER)
ALL_TARGET=	basic
PLIST_SUB+=	TRACER="@comment "
.else
PLIST_SUB+=	TRACER=""
MAKE_ENV+=	PATH=${PREFIX}/jdk1.1.8/bin:$$PATH
.endif

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/nhc98 +docs
.endif

MAN1=		harch.1 hmake.1	hp2graph.1 nhc98.1 \
		hat-detect.1 hat-observe.1 hat-stack.1 hat-trail.1

pre-fetch:
.if !defined(WITH_TRACER)
	@${ECHO} ""
	@${ECHO} "	To build nhc98 with the tracer (requires JAVA)"
	@${ECHO} "	define WITH_TRACER"
	@${ECHO} ""
.else
	@${ECHO} ""
	@${ECHO} "	Building nhc98 with the tracer (requires JAVA)"
	@${ECHO} ""
.endif

post-patch:
	@${PERL} -pi.orig -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile.inc

# We need this to ensure that the libs will be installed into
# ${PREFIX}/lib/nhc98. Otherwise the libs will be installed
# into the build directory. The configure option won't work in the
# ports system.
pre-install:
	${RM} -f ${WRKSRC}/include/*.orig
	${SED} -e "s#LIBDIR=.*##" \
	       < ${WRKSRC}/targets/ix86-FreeBSD/config.cache \
	       > ${WRKSRC}/targets/ix86-FreeBSD/config.cache.fix1
	${ECHO} "LIBDIR=${PREFIX}/lib/nhc98" \
	        >> ${WRKSRC}/targets/ix86-FreeBSD/config.cache.fix1
	${RM} ${WRKSRC}/targets/ix86-FreeBSD/config.cache
	${MV} ${WRKSRC}/targets/ix86-FreeBSD/config.cache.fix1 \
	      ${WRKSRC}/targets/ix86-FreeBSD/config.cache

post-install:
	${SED} -e "s#/usr/doc/nhc98#${PREFIX}/share/doc/nhc98#" \
	       < ${WRKSRC}/man/nhc98.1 > ${WRKSRC}/man/nhc98.1.fix
	${INSTALL_MAN} ${WRKSRC}/man/nhc98.1.fix ${PREFIX}/man/man1/nhc98.1
	${RM} ${WRKSRC}/man/nhc98.1.fix

.include <bsd.port.mk>
