PORTNAME=	devtoolset
PORTVERSION=	11.1
DISTVERSIONPREFIX=	11-
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_CENTOS_LINUX}
MASTER_SITE_SUBDIR=	altarch/7/sclo/aarch64/rh/Packages/d/:DEFAULT,aarch64 \
			centos/7/sclo/x86_64/rh/Packages/d/:DEFAULT,amd64 \
			altarch/7/sclo/i386/rh/Packages/d/:DEFAULT,i386 \
			centos/7/sclo/Source/rh/:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Developer Toolset collection (CentOS ${LINUX_DIST_VER})
WWW=		https://gcc.gnu.org/

ONLY_FOR_ARCHS=	amd64

USES=		linux:c7
USE_LINUX=	devtools
USE_LINUX_RPM=	nolib
USE_LDCONFIG=	yes

BIN_DISTNAMES=	${DISTNAME} \
		${PORTNAME}-${DISTVERSIONPREFIX}binutils-2.36.1-1.el7.2 \
		${PORTNAME}-${DISTVERSIONPREFIX}gcc-11.2.1-9.1.el7 \
		${PORTNAME}-${DISTVERSIONPREFIX}gcc-c++-11.2.1-9.1.el7 \
		${PORTNAME}-${DISTVERSIONPREFIX}gcc-gfortran-11.2.1-9.1.el7 \
		${PORTNAME}-${DISTVERSIONPREFIX}libstdc++-devel-11.2.1-9.1.el7 \
		${PORTNAME}-${DISTVERSIONPREFIX}toolchain-11.1-2.el7
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE \
		${PORTNAME}-${DISTVERSIONPREFIX}binutils-2.36.1-1.el7.2${SRC_SUFX}:SOURCE \
		${PORTNAME}-${DISTVERSIONPREFIX}gcc-11.2.1-9.1.el7${SRC_SUFX}:SOURCE

post-install:
	${FIND} ${STAGEDIR} -name '*la' -delete

.include <bsd.port.mk>
