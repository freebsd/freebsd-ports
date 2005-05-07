# ports collection makefile for:	Berkeley DB v4.3
# Date created:				2004-11-10
# Whom:					Matthias Andree <matthias.andree@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	db43
PORTVERSION=	4.3.28
CATEGORIES=	databases
MASTER_SITES=	http://downloads.sleepycat.com/
PKGNAMESUFFIX?=
DISTNAME?=	db-${PORTVERSION}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://www.sleepycat.com/update/${PORTVERSION}/
PATCH_DIST_STRIP=	-d ..

MAINTAINER=	matthias.andree@gmx.de
COMMENT=	The Berkeley DB package, revision 4.3

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

USE_REINPLACE=		yes
INSTALLS_SHLIB=		yes
USE_LIBTOOL_VER=	15
CONFIGURE_SCRIPT=	../dist/configure
LIBTOOLFILES=		${CONFIGURE_SCRIPT}
CONFIGURE_TARGET=	--target=${ARCH}-portbld-freebsd${OSREL}
BDBVER=			${PORTVERSION:R}
BDBMINOR=		${BDBVER:E:S/^\.//}
BDBDIR=			BerkeleyDB.${BDBVER}
CONFIGURE_ARGS=		--enable-compat185 --enable-dump185 \
			--enable-cxx --enable-dynamic \
			--enable-rpc \
			--includedir=${PREFIX}/include/${PORTNAME} \
			--libdir=${PREFIX}/lib/${PORTNAME} \
			--bindir=${PREFIX}/bin/${PORTNAME}
INSTALL_TARGET=		install_include install_lib install_utilities
.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_docs docdir=${DOCSDIR}
PORTDOCS=		*
.endif

pre-patch:
	@${REINPLACE_CMD} -Ee 's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	${CHMOD} u+w ${WRKSRC}/../dist/configure

post-install:
.for i in libdb libdb_cxx
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${PREFIX}/lib/${i}-${BDBVER}.so
.endfor
.if !defined(NOPORTDOCS)
	@${RMDIR} ${DOCSDIR}/ref/splash 2>/dev/null || :
.endif
	cd ${PREFIX}/bin/${PORTNAME} ; \
	for i in * ; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; done
.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
CONFIGURE_ARGS+=	--with-mutex=x86/gcc-assembly
.endif

.include <bsd.port.post.mk>
