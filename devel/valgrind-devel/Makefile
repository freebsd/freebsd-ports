# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
PORTVERSION=	3.17.0.g20200723
DISTVERSIONPREFIX=	freebsd-
#PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	pjfloyd@wanadoo.fr
COMMENT=	Memory debugging and profiling tool

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

DOCS_BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
MANPAGES_BUILD_DEPENDS=	docbook-xsl>=0:textproc/docbook-xsl \
		xsltproc:textproc/libxslt
MPI_LIB_DEPENDS=	libmpich.so:net/mpich

USES=		pathfix pkgconfig gmake perl5 shebangfix autoreconf
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
OPTIONS_SUB=	yes
SHEBANG_FILES=	callgrind/callgrind_annotate.in callgrind/callgrind_control.in
SSP_UNSAFE=		yes
LIB32_PATH?=	${DESTDIR}/usr/lib32/libc.so

CONFLICTS=	valgrind-[0-9]*

USE_GITHUB=	yes
GH_TAGNAME=	d4fba6a
GH_ACCOUNT=	paulfloyd
GH_PROJECT=	freebsd_valgrind

PORTDOCS=	html

OPTIONS_DEFINE=		DOCS MANPAGES MPI
OPTIONS_DEFINE_amd64=	32BIT
OPTIONS_DEFAULT=	MANPAGES
.if exists(${LIB32_PATH})
OPTIONS_DEFAULT_amd64=	32BIT
.endif
32BIT_DESC=	Enable debugging of 32-bit programs (requires lib32)
MPI_DESC=	Enable build of MPI wrappers

CONFIGURE_ENV+=	ac_cv_path_PERL=${PERL}

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
	@${RM} -r ${WRKSRC}/docs/html
.endif

post-build:
.if ${PORT_OPTIONS:MMANPAGES}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} man-pages
.endif
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} html-docs
.endif

.include <bsd.port.mk>
