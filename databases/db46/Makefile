# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	db46
PORTVERSION=	4.6.21.4
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/ \
PKGNAMEPREFIX?=
DISTNAME=	db-${PORTVERSION:R}
DIST_SUBDIR=	bdb

PATCH_SITES=	http://download.oracle.com/berkeley-db/patches/db/${PORTVERSION:R}/
PATCHFILES=	patch.4.6.21.1 patch.4.6.21.2 patch.4.6.21.3 patch.4.6.21.4
PATCH_DIST_STRIP=	-d .. -l
# * patch.4.6.21.1: -----------------------------------------------------------
# Fixes a race condition between checkpoint and DB->close which can result in
# the checkpoint thread self-deadlocking. [#15692]
# * 4.6.21.2: -----------------------------------------------------------------
# Fixes the potential for the wrong number of mutexes to be allocated. This
# issue could cause applications with multiple cache regions to see undefined
# behavior in rare cases under load. [#16178]
# * 4.6.21.3: -----------------------------------------------------------------
# Replication clients should be able to open a sequence. [#16406]
# * 4.6.21.4: -----------------------------------------------------------------
# Fixes a bug which could lead to slow performance of internal init under
# Replication Manager, as evidenced by "queue limit exceeded" messages in
# verbose replication diagnostic output. [#15788]

# I allow matthias.andree@gmx.de and all freebsd committer to do changes
# to this package.

MAINTAINER=	gslin@gslin.org
COMMENT=	The Berkeley DB package, revision 4.6

DEPRECATED=	Please use databases/db5 or db6 for new installs.

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

NO_STAGE=	yes
post-install:
.for i in libdb libdb_cxx
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${PREFIX}/lib/${i}-${BDBVER}.so
.endfor
	cd ${PREFIX}/bin/${PORTNAME} ; \
	for i in * ; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER} ; done

.include <bsd.port.mk>
