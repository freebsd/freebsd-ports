# Created by: Yuri Victorovich <yuri@tsoft.com>
# $FreeBSD$

PORTNAME=	google-perftools
PORTVERSION=	1.8.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	vd/${PORTNAME}

MAINTAINER=	yuri@tsoft.com
COMMENT=	Fast, multi-threaded malloc() and nifty performance analysis tools

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAN1=		pprof.1

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USES=	pathfix

NO_STAGE=	yes
post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e \
		'/^install-data-am:/ s|install-dist_docDATA||' \
		${WRKSRC}/Makefile.in
.endif

post-build:
	@${ECHO}
	@${ECHO} "Please run 'make check' and verify there are no failing testcases on your system."
	@${ECHO} "Report any testcase failures to http://code.google.com/p/google-perftools/issues/list"
	@${ECHO}

# four of the tests are known to fail on 7.0, uncomment this as soon as this is fixed
#regression-test: check

check: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--enable-frame-pointers
.endif
.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=	Does not build, assembly not supported, see PR-94: http://code.google.com/p/google-perftools/issues/detail?id=94&can=1
.endif

.include <bsd.port.post.mk>
