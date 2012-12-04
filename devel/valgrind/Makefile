# Created by: Simon Barner <barner@gmx.de>
# $FreeBSD$

PORTNAME=	valgrind
PORTVERSION=	3.7.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/:dist \
		http://mirror.shatow.net/freebsd/${PORTNAME}/:dist \
		http://mirror.shatow.net/freebsd/${PORTNAME}/:manpages
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}-3
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:dist \
		${DISTNAME}-manpages${EXTRACT_SUFX}:manpages

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Memory debugging and profiling tool

CONFLICTS=	valgrind-snapshot-[0-9]*

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
USE_GNOME=	gnomehack
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	mpich:${PORTSDIR}/net/mpich2
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

post-install:
	(cd ${WRKDIR}/valgrind-manpages/ && ${COPYTREE_SHARE} \* ${MANPREFIX}/man/man1)
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700104
IGNORE=	your FreeBSD version is not supported
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64="" ARCH=amd64
. if !exists(/usr/lib32)
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=	X86="@comment "
. else
PLIST_SUB+=	X86=""
. else
. endif
.else
PLIST_SUB+=	X86="" ARCH=x86
PLIST_SUB+=	AMD64="@comment "
.endif

.include <bsd.port.post.mk>
