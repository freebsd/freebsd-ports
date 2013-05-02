# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
PORTVERSION=	3.8.0
PORTEPOCH=	1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/stass/valgrind-freebsd/downloads/:dist \
		http://mirror.shatow.net/freebsd/${PORTNAME}/:dist \
		http://mirror.shatow.net/freebsd/${PORTNAME}/:manpages
PKGNAMESUFFIX=	-snapshot
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:dist \
		${DISTNAME}-manpages${EXTRACT_SUFX}:manpages

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

OPTIONS_DEFINE=	MPI
MPI_DESC=	Enable build of MPI wrappers

USE_BZIP2=	yes
USE_GMAKE=	yes
USES=	pathfix pkgconfig
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	mpich:${PORTSDIR}/net/mpich2
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

EXTRA_PATCHES=	${PATCHDIR}/extra-patch-libsupc++

post-install:
	(cd ${WRKDIR}/valgrind-manpages/ && ${COPYTREE_SHARE} \* ${MANPREFIX}/man/man1)

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
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

.include <bsd.port.post.mk>
