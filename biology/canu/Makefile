# $FreeBSD$

PORTNAME=		canu
DISTVERSIONPREFIX=	v
DISTVERSION=		1.8
PORTREVISION=		2
CATEGORIES=		biology java perl5

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Single molecule sequence assembler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}-${PORTVERSION}/README.license.GPL

BROKEN_aarch64=		fails to link: undefined reference to omp_set_num_threads
BROKEN_armv6=		fails to install: mv: rename site_perl to /wrkdirs/usr/ports/biology/canu/work/canu-1.7/src/usr/local/FreeBSD-armv6/lib/perl5/site_perl: No such file or directory
BROKEN_armv7=		fails to install: mv: rename site_perl to /wrkdirs/usr/ports/biology/canu/work/canu-1.7/src/usr/local/FreeBSD-armv7/lib/perl5/site_perl: No such file or directory

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
RUN_DEPENDS=	gnuplot:math/gnuplot

USES=		compiler:openmp gmake perl5
USE_JAVA=	yes
USE_GITHUB=	yes

JAVA_RUN=	yes
JAVA_VERSION=	1.8+
GH_ACCOUNT=	marbl

WRKSRC_SUBDIR=	src
# Makefile compiles directly into ${DESTDIR}${PREFIX}
MAKE_ENV+=	DESTDIR=${WRKSRC}

post-patch:
	${REINPLACE_CMD} \
		-e 's|-O4||g' \
		-e 's|-funroll-loops||g' \
		-e 's|-fexpensive-optimizations||g' \
		-e 's|amd64|${ARCH}|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|\\$$bin/mhap-|${JAVAJARDIR}/mhap-|g' \
		${WRKSRC}/pipelines/canu/OverlapMhap.pm
	${REINPLACE_CMD} -e 's|RealBin/lib|RealBin/../${SITE_PERL_REL}/canu|g' \
		${WRKSRC}/pipelines/canu.pl

# Upstream does not want to use lib/perl5/site_perl
post-build:
	@${MKDIR} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/perl5
	${MV} ${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/site_perl \
		${WRKSRC}${PREFIX}/FreeBSD-${ARCH}/lib/perl5

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}
	(cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && \
		${COPYTREE_BIN} bin ${STAGEDIR}${PREFIX})
	# STRIP_CMD fails without this on 11.1 under poudriere
	@${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} \
		`file ${STAGEDIR}${PREFIX}/bin/* | ${GREP} ELF | cut -d : -f 1`
	(cd ${WRKSRC}${PREFIX}/FreeBSD-${ARCH} && \
		${COPYTREE_SHARE} "lib share" ${STAGEDIR}${PREFIX})

.include <bsd.port.mk>
