# $FreeBSD$

PORTNAME=	canu
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
CATEGORIES=	biology java perl5

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Single molecule sequence assembler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/README.license.GPL

LIB_DEPENDS+=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS+=	gnuplot:math/gnuplot

USES=		compiler:openmp gmake perl5
USE_JAVA=	yes
JAVA_RUN=	yes
JAVA_VERSION=	1.8+

USE_GITHUB=	yes
GH_ACCOUNT=	marbl

BUILD_WRKSRC=	${WRKSRC}/src

# Makefile compiles directly into ${DESTDIR}${PREFIX}
MAKE_ENV+=	DESTDIR=${BUILD_WRKSRC}

post-patch:
	${REINPLACE_CMD} \
		-e 's|-O4||g' \
		-e 's|-funroll-loops||g' \
		-e 's|-fexpensive-optimizations||g' \
		-e 's|amd64|${ARCH}|g' \
		${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|\\$$bin/mhap-|${JAVAJARDIR}/mhap-|g' \
		${BUILD_WRKSRC}/pipelines/canu/OverlapMhap.pm
	${REINPLACE_CMD} -e 's|RealBin/lib|RealBin/../${SITE_PERL_REL}/canu|g' \
		${BUILD_WRKSRC}/pipelines/canu.pl

# Reorganize according to filesystem hierarchy standard
post-build:
	@${MKDIR} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${SITE_PERL_REL}
	@${MV} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/lib/canu \
		${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${SITE_PERL_REL}
	@${RMDIR} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/lib
	@${MV} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/*.a \
		${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib
	@${MKDIR} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${JAVAJARDIR:S,^${PREFIX}/,,}
	@${MV} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/*.jar \
		${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/${JAVAJARDIR:S,^${PREFIX}/,,}
	@${RM} ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH}/bin/canu.defaults

do-install:
	cd ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH} && ${COPYTREE_BIN} bin \
		${STAGEDIR}${PREFIX}
	# STRIP_CMD fails without this on 11.1 under poudriere
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} \
		`file ${STAGEDIR}${PREFIX}/bin/* | ${GREP} ELF | cut -d : -f 1`
	cd ${BUILD_WRKSRC}${PREFIX}/FreeBSD-${ARCH} && ${COPYTREE_SHARE} "lib share" \
		${STAGEDIR}${PREFIX}

.include <bsd.port.mk>
