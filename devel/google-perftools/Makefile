# New ports collection makefile for:	google-sparsehash
# Date created:				07 January 2007
# Whom:					Yuri Victorovich <yuri@tsoft.com>
#
# $FreeBSD$
#

PORTNAME=	google-perftools
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME}

MAINTAINER=	yuri@tsoft.com
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN1=		pprof.1

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-build:
	@${ECHO}
	@${ECHO} "Be aware that 3 (sampling_test.sh,profiledata_unittest,profiler_unittest.sh) out of 29 self tests is known to fail."
	@${ECHO} "Run 'make check' and try to fix that. Thanks!"
	@${ECHO} "Be aware that another self test (profiler_unittest) can randomly fail on the loaded system."
	@${ECHO}

# four of the tests are known to fail on 7.0, uncomment this as soon as this is fixed
#regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-frame-pointers
.endif
.if ${ARCH} == "ia64" || ${ARCH} == "sparc64"
BROKEN=	Does not build, ia64 assembly not supported, see PR-94: http://code.google.com/p/google-perftools/issues/detail?id=94&can=1
.endif

.include <bsd.port.post.mk>
