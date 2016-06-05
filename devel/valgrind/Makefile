# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
PORTVERSION=	3.10.1.20160113
DISTVERSIONPREFIX=	freebsd-
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://bitbucket.org/${BB_ACCOUNT}/${BB_PROJECT}/get/${BB_COMMIT}.tar.gz?dummy=/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Memory debugging and profiling tool

BB_COMMIT=	ce1acb28953f
BB_ACCOUNT=	stass
BB_PROJECT=	valgrind-freebsd

LICENSE=	GPLv2

CONFLICTS=	valgrind-devel-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

LIB32_PATH?=	${DESTDIR}/usr/lib32/libc.so

OPTIONS_DEFINE=		DOCS MANPAGES MPI
OPTIONS_DEFINE_amd64=	32BIT
OPTIONS_DEFAULT=	MANPAGES
.if exists(${LIB32_PATH})
OPTIONS_DEFAULT_amd64=	32BIT
.endif
32BIT_DESC=	Enable debugging of 32-bit programs (requires lib32)
MPI_DESC=	Enable build of MPI wrappers

DOCS_BUILD_DEPENDS=    docbook-xsl>=0:textproc/docbook-xsl \
                       xsltproc:textproc/libxslt
MANPAGES_BUILD_DEPENDS=        docbook-xsl>=0:textproc/docbook-xsl \
                       xsltproc:textproc/libxslt
MPI_LIB_DEPENDS=	libmpich.so:net/mpich2

OPTIONS_SUB=	yes
USES=		pathfix pkgconfig gmake perl5 shebangfix autoreconf
PATHFIX_MAKEFILEIN=	Makefile.am
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
SHEBANG_FILES=	callgrind/callgrind_annotate.in callgrind/callgrind_control.in

EXTRA_PATCHES=	\
		${FILESDIR}/accept4_syscall.patch:-p1 \
		${FILESDIR}/jail_syscalls.patch:-p1 \
		${FILESDIR}/kldload_syscalls.patch:-p1 \
		${FILESDIR}/missing_fcntls.patch:-p1

PORTDOCS=	html

WRKSRC=		${WRKDIR}/${BB_ACCOUNT}-${BB_PROJECT}-${BB_COMMIT}

CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL}

USE_GCC=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARCH=amd64
. if !${PORT_OPTIONS:M32BIT}
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=	X86="@comment "
. else
.  if !exists(${LIB32_PATH})
IGNORE=The lib32 distribution was not found. Please install the lib32\
distribution or run 'make config' and uncheck 32BIT option
.  endif
PLIST_SUB+=	X86=""
. endif
.else
PLIST_SUB+=	X86="" ARCH=x86
PLIST_SUB+=	AMD64="@comment "
.endif

.if !${PORT_OPTIONS:MDOCS}
post-patch:
	@${RM} -rf ${WRKSRC}/docs/html
.endif

post-build:
.if ${PORT_OPTIONS:MMANPAGES}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man-pages
.endif
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html-docs
.endif

.include <bsd.port.mk>
