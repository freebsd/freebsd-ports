# ports collection makefile for:	Berkeley DB v4
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <ozz@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db4
PORTVERSION=	4.0.14
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

#PATCH_SITES=	${MASTER_SITES}
#PATCHFILES=	patch.${PORTVERSION}.1 patch.${PORTVERSION}.2
#PATCH_DIST_STRIP= -d ${WRKDIR}/${DISTNAME}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-compat185 --enable-dump285 \
		--enable-cxx --enable-dynamic \
		--includedir=${PREFIX}/include/db4
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install_docs
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
