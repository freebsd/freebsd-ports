# ports collection makefile for:	Berkeley DB v4
# Date created:				2003-01-04
# Whom:					Matthias Andree <matthias.andree@web.de>
#
# $FreeBSD$
#

PORTNAME=	db41
PORTVERSION=	4.1.25
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/
PKGNAMESUFFIX?=
DISTNAME?=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
PATCHFILES=	patch.${PORTVERSION}.1
PATCH_DIST_STRIP= -d ${WRKDIR}/${DISTNAME}

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	The Berkeley DB package, revision 4.1

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-compat185 --enable-dump185 \
		--enable-cxx --enable-dynamic \
		--includedir=${PREFIX}/include/db41
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install_docs
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-mutex=x86/gcc-assembly
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
