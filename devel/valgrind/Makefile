# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
PORTVERSION=	3.8.1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/stass/valgrind-freebsd/downloads/ \
		http://mirror.shatow.net/freebsd/${PORTNAME}/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Memory debugging and profiling tool

LICENSE=	GPLv2

CONFLICTS=	valgrind-snapshot-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

MAN1=		callgrind_control.1 \
		callgrind_annotate.1 \
		valgrind.1 \
		ms_print.1 \
		cg_annotate.1

OPTIONS_DEFINE=	MPI
MPI_DESC=	Enable build of MPI wrappers

MPI_LIB_DEPENDS=	mpich:${PORTSDIR}/net/mpich2

OPTIONS_SUB=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=	pathfix pkgconfig
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	html

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARCH=amd64
. if !exists(/usr/lib32/libc.so)
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=	X86="@comment "
. else
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
