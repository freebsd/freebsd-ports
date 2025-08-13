PORTNAME=	racket
PORTVERSION=	8.17
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://mirror.racket-lang.org/installers/${PORTVERSION}/ \
		http://www.cs.utah.edu/plt/installers/${PORTVERSION}/ \
		http://www.eecs.northwestern.edu/racket/${PORTVERSION}/ \
		http://mirror.csclub.uwaterloo.ca/racket/racket-installers/${PORTVERSION}/ \
		http://mirror.informatik.uni-tuebingen.de/mirror/racket/${PORTVERSION}/ \
		http://racket.infogroep.be/${PORTVERSION}/
PKGNAMESUFFIX=	-minimal
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}-src-builtpkgs
DIST_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX}/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Interactive, integrated, graphical Scheme programming environment
WWW=		https://racket-lang.org/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

NOT_FOR_ARCHS=	riscv64
NOT_FOR_ARCHS_REASON=	unsupported platform

LIB_DEPENDS=	libffi.so:devel/libffi \
		liblz4.so:archivers/liblz4

USES=		cpe gmake iconv libtool localbase tar:tgz
CPE_VENDOR=	${PORTNAME}-lang

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-liblz4 \
		--enable-pthread \
		--mandir=${PREFIX}/share/man

CONFLICTS=	racket

REINPLACE_ARGS=	-i ""

PATCH_WRKSRC=	${WRKDIR}/racket-${PORTVERSION}
WRKSRC=		${WRKDIR}/racket-${PORTVERSION}/src

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFINE_amd64=	FUTURES JIT
OPTIONS_DEFINE_i386=	FUTURES JIT
OPTIONS_DEFAULT=	CS
OPTIONS_DEFAULT_powerpc=	BC
OPTIONS_DEFAULT_powerpc64=	BC
OPTIONS_DEFAULT_powerpc64le=	BC
OPTIONS_SINGLE=		BACKEND
OPTIONS_SINGLE_BACKEND=	BC CS
OPTIONS_EXCLUDE_powerpc=	CS
OPTIONS_EXCLUDE_powerpc64=	CS
OPTIONS_EXCLUDE_powerpc64le=	CS
OPTIONS_SUB=		yes

BACKEND_DESC=	Racket Backend
BC_DESC=	Build ByteCode backend (legacy)
CS_DESC=	Build ChezScheme backend
FUTURES_DESC=	Enable futures (only for BC backend)
JIT_DESC=	Enable JIT compiler (only for BC backend)

BC_CONFIGURE_ON=		--enable-bconly \
				--enable-libffi \
				--enable-places
CS_CONFIGURE_ON=		--enable-csonly \
				--enable-mach=${CHEZ_MACHTYPE}
FUTURES_IMPLIES=		JIT
FUTURES_PREVENTS=		CS
FUTURES_PREVENTS_MSG=		CS enables futures by default
FUTURES_CONFIGURE_ENABLE=	futures
JIT_PREVENTS=			CS
JIT_PREVENTS_MSG=		CS enables jit by default
JIT_CONFIGURE_ENABLE=		jit

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CHEZ_MACHTYPE=	ta6fb
.elif ${ARCH} == "arm"
CHEZ_MACHTYPE=	tarm32fb
.elif ${ARCH} == "arm64"
CHEZ_MACHTYPE=	tarm64fb
.elif ${ARCH} == "i386"
CHEZ_MACHTYPE=	ti3fb
.elif ${ARCH} == "powerpc"
CHEZ_MACHTYPE=	tppc32fb
.elif ${ARCH} == "powerpc64"
CHEZ_MACHTYPE=	tpb64b
.elif ${ARCH} == "powerpc64le"
CHEZ_MACHTYPE=	tpb64l
.endif

.if ${ARCH:Mpowerpc64*}
CONFIGURE_ARGS+=	--enable-pb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/ChezScheme/configure ${WRKSRC}/bc/configure ${WRKSRC}/cs/c/configure

post-install:
	${FIND} ${STAGEDIR}${PREFIX} -type d -empty -delete
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/racket/gracket

.include <bsd.port.mk>
