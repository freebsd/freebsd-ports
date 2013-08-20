# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
PORTVERSION=	3.8.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/stass/valgrind-freebsd/downloads/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/
PKGNAMESUFFIX=	-snapshot
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Memory debugging and profiling tool

LICENSE=	GPLv2

CONFLICTS=	valgrind-[0-9]*
LATEST_LINK=	valgrind-snapshot

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		callgrind_control.1 \
		callgrind_annotate.1 \
		valgrind.1 \
		ms_print.1 \
		cg_annotate.1

LIB32_PATH?=	${DESTDIR}/usr/lib32/libc.so

OPTIONS_DEFINE=		MPI
OPTIONS_DEFINE_amd64=	32BIT
.if exists(${LIB32_PATH})
OPTIONS_DEFAULT_amd64=	32BIT
.endif
32BIT_DESC=	Enable debugging of 32-bit programs (requires lib32)
MPI_DESC=	Enable build of MPI wrappers

MPI_LIB_DEPENDS=	mpich:${PORTSDIR}/net/mpich2

OPTIONS_SUB=	yes
USE_BZIP2=	yes
USES=		pathfix pkgconfig gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	html

WRKSRC=		${WRKDIR}/${DISTNAME}

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

.include <bsd.port.mk>
