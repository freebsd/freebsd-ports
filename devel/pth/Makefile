PORTNAME=	pth
PORTVERSION=	2.0.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU
PKGNAMESUFFIX?=	# empty

MAINTAINER=	vd@FreeBSD.org
COMMENT=	GNU Portable Threads

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-optimize \
		--enable-batch \
		--includedir="${PREFIX}/include/pth" \
		--libdir="${PREFIX}/lib/pth"
USES=		libtool
USE_LDCONFIG=	${PREFIX}/lib/pth

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

CONFLICTS?=	pth-hard-2.*

.include <bsd.port.options.mk>

.if ${PKGNAMESUFFIX} == "-hard"
CONFIGURE_ARGS+=	--enable-syscall-hard --disable-syscall-soft
PLIST_SUB+=	PTHREAD="@comment "
.else
CONFIGURE_ARGS+=	--enable-syscall-soft --enable-pthread
PLIST_SUB+=	PTHREAD=""
.endif

post-patch:
.if ! ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
	${REINPLACE_CMD} -e \
		's|-funroll-loops -fstrength-reduce -fomit-frame-pointer -ffast-math||' \
		${WRKSRC}/configure
.endif

post-build:
	@${ECHO_MSG} "===>  Use 'make test' to run a quick test suite."

test: build
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test

.include <bsd.port.mk>
