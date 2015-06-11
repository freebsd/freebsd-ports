# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	db48
PORTVERSION=	4.8.30.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://download.oracle.com/berkeley-db/
PKGNAMEPREFIX?=
DISTNAME=	db-${PORTVERSION:R}
DIST_SUBDIR=	bdb

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	The Berkeley DB package, revision 4.8

DEPRECATED=		Please migrate to db5 or db6
# The port is not to be removed unless the bitcoin-related ports can
# go without this.
EXPIRATION_DATE=	2015-07-31

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKDIR}/${DISTNAME}/LICENSE

BDBVER=		${PORTVERSION:R:R}
CONFIGURE_ARGS=	--enable-compat185 --enable-dump185 --enable-cxx \
		--includedir=${PREFIX}/include/${PORTNAME} \
		--libdir=${PREFIX}/lib/${PORTNAME} \
		--bindir=${PREFIX}/bin/${PORTNAME}
CONFIGURE_SCRIPT=	../dist/configure
USES=		libtool:keepla
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install_include install_lib install_utilities
WRKSRC=		${WRKDIR}/${DISTNAME}/build_unix
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == "armv6"
# db48 uses a deprecated instruction for mutexes on ARM, fbsd bug#197227
CONFIGURE_ARGS+=	--enable-posixmutexes
.endif

post-patch:
	${REINPLACE_CMD} -Ee 's|--mode=install cp -p|--mode=install ${INSTALL} -s|;' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
.for i in libdb libdb_cxx
	${LN} -s -f ${PORTNAME}/${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -s -f ${i}-${BDBVER}.so.0 ${STAGEDIR}${PREFIX}/lib/${i}-${BDBVER}.so
.endfor
	cd ${STAGEDIR}${PREFIX}/bin/${PORTNAME}; \
	for i in *; do ${LN} -s -f ${PORTNAME}/$$i ../$$i-${BDBVER}; done

.include <bsd.port.mk>
