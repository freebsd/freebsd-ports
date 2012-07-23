# Ports collection makefile for:	valgrind
# Date created:				April 19 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	valgrind
PORTVERSION=	3.7.0
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
DISTNAME=	${PORTNAME}-freebsd-${PORTVERSION}-3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A (memory) debugging and profiling tool

CONFLICTS=	valgrind-snapshot-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

BUILD_DEPENDS=	pkg-config>0:${PORTSDIR}/devel/pkg-config

OPTIONS_DEFINE=	MPI
MPI_DESC=	Enable build of MPI wrappers

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPI}
LIB_DEPENDS+=	mpich.2:${PORTSDIR}/net/mpich2
PLIST_SUB+=	MPI=""
.else
PLIST_SUB+=	MPI="@comment "
.endif

post-install:
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
