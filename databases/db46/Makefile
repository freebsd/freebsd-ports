# New ports collection makefile for:	db46
# Date created:		2007-07-26
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	db46
PORTVERSION=	4.6.21.1
CATEGORIES=	databases
MASTER_SITES=	http://download-west.oracle.com/berkeley-db/ \
		http://download-east.oracle.com/berkeley-db/ \
		http://download-uk.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
DISTNAME=	db-${PORTVERSION:R}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://www.oracle.com/technology/products/berkeley-db/xml/update/${PORTVERSION:R}/
PATCHFILES=	patch.4.6.21.1
PATCH_DIST_STRIP=	-d ..
# * patch.4.6.21.1: -----------------------------------------------------------
# Fixes a race condition between checkpoint and DB->close which can result in
# the checkpoint thread self-deadlocking. [#15692]

# I allow matthias.andree@gmx.de and all freebsd committer to do changes
# to this package.
MAINTAINER=	gslin@gslin.org
COMMENT=	The Berkeley DB package, revision 4.6

BDBVER=		${PORTVERSION:R:R}
CONFIGURE_ARGS=	--enable-compat185 --enable-dump185 --enable-cxx \
		--enable-dynamic --enable-rpc --enable-pthread_api \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME}
CONFIGURE_SCRIPT=	../dist/configure
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install_include install_lib install_utilities
LIBTOOLFILES=	${CONFIGURE_SCRIPT}
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
USE_LDCONFIG=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	install_docs docdir=${DOCSDIR}
PORTDOCS=	*
.endif

post-install:
.for i in libdb libdb_cxx
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${PREFIX}/lib/${i}-${BDBVER}.so
.endfor
	cd ${PREFIX}/bin/${PORTNAME} ; \
	for i in * ; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; done

.include <bsd.port.mk>
