PORTNAME=	llvm
PORTVERSION=	17.0.6
DISTVERSIONSUFFIX=	-5.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	LLVM suite (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/Software/dbus

LICENSE=	GPLv2+

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	elfutils-libelf python3
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}-${DISTVERSIONFULL} \
		${PORTNAME}-devel-${DISTVERSIONFULL} \
		${PORTNAME}-libs-${DISTVERSIONFULL} \
		${PORTNAME}-static-${DISTVERSIONFULL}

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/usr/include \
		${STAGEDIR}${PREFIX}/usr/lib64/cmake

.include <bsd.port.mk>
