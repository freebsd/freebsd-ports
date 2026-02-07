PORTNAME=	libepoll-shim
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.20240608
CATEGORIES=	devel

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Small epoll implementation using kqueue
WWW=		https://github.com/jiixyj/epoll-shim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

FLAVORS=	default i386
FLAVOR?=	${FLAVORS:[1]}
i386_PKGNAMESUFFIX=	-i386
i386_PLIST=	${.CURDIR}/pkg-plist.i386

USES=		cmake compiler:c11
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_PROJECT=	epoll-shim
PLIST_SUB=	SHIM_EVENTFD="${exists(/usr/include/sys/eventfd.h):?@comment :}" \
	SHIM_TIMERFD="${exists(/usr/include/sys/timerfd.h):?@comment :}"

.include <bsd.port.pre.mk>

.if ${ARCH} != amd64 && ${FLAVOR:U} == i386
IGNORE=		i386 flavor only makes sense for amd64 arch
.endif

.if ${FLAVOR:U} == i386
CFLAGS+=	-m32
CMAKE_ARGS+=	-DCMAKE_INSTALL_LIBDIR=lib32

post-stage:
	${RM} -r ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/libdata
.endif

do-test:
	# Exclude certain tests in resource restricted environments
	@(if [ `ulimit -n` -lt 20100 ]; then \
	    ${ECHO} "Skipping test perf-many-fds.perf_many_fds__perf"; \
	    SKIP_TESTS="-E ^(perf-many-fds.perf_many_fds__perf"; \
	    if [ `ulimit -n` -lt 1100 ]; then \
	        ${ECHO} "Skipping test timerfd-test.timerfd__many_timers"; \
	        SKIP_TESTS=$$SKIP_TESTS"|timerfd-test.timerfd__many_timers"; \
	    fi; \
	    SKIP_TESTS=$$SKIP_TESTS")$$"; \
	fi; \
	cd ${TEST_WRKSRC} && \
	${SETENV} ${TEST_ENV} ctest -C ${CMAKE_BUILD_TYPE} $$SKIP_TESTS)

.include <bsd.port.post.mk>
