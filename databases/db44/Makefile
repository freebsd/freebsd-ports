# Created by: Matthias Andree <matthias.andree@gmx.de>
# $FreeBSD$

PORTNAME=	db44
PORTVERSION=	4.4.20.4
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/ 
PKGNAMESUFFIX?=
DISTNAME=	db-4.4.20
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 4.4

WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix

DEPRECATED=	Please use databases/db5 or db6 for new installs.

USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
DEBUG_FLAGS=		-g -O1	# need -O1 for inline assembly
CONFIGURE_SCRIPT=	../dist/configure
LIBTOOLFILES=		${CONFIGURE_SCRIPT}
BDBVER=			${PORTVERSION:R:R}
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

NO_STAGE=	yes
pre-patch:
	@${REINPLACE_CMD} -Ee 's|-l?pthread|${PTHREAD_LIBS}|g' ${WRKSRC}/${CONFIGURE_SCRIPT}

pre-configure:
	@${CHMOD} u+w ${WRKSRC}/../dist/configure

post-configure:
	@${REINPLACE_CMD} -e '/^extern  void db_rpc_serverprog/ d;' ${WRKSRC}/db_server.h

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

.include <bsd.port.mk>
