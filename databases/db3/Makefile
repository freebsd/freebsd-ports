# ports collection makefile for:	Berkeley DB v3
# Date created:				16 August 2000
# Whom:					Sergey Osokin aka oZZ <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	db3
PORTVERSION=	3.3.11
PORTREVISION=	1
PORTEPOCH?=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/update/snapshot/
DISTNAME=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
PATCHFILES=	patch.${PORTVERSION}.1 patch.${PORTVERSION}.2
PATCH_DIST_STRIP=	-d ${WRKDIR}/${DISTNAME}

MAINTAINER?=	matthias.andree@gmx.de
COMMENT?=	The Berkeley DB package, revision 3.3

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes
USE_LIBTOOL_VER=	13
CONFIGURE_SCRIPT=	../dist/configure
LIBTOOLFILES=		${CONFIGURE_SCRIPT}
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx \
			--enable-dynamic \
			--prefix=${PREFIX} \
			--includedir=${PREFIX}/include/db3
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALL_TARGET=		install_include install_lib install_utilities
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_docs docdir=${DOCSDIR}
PORTDOCS=		*

post-install:
	${RMDIR} ${DOCSDIR}/ref/splash
.endif

pre-patch:
	@${REINPLACE_CMD} -Ee 's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-patch:
	@${CHMOD} 755 ${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/../dist/configure

.include <bsd.port.mk>
