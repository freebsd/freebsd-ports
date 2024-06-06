PORTNAME=	alsa-lib
PORTVERSION=	1.2.10
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	audio linux
PKGNAMESUFFIX=	-devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Advanced Linux Sound Architecture headers (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.alsa-project.org/

LICENSE=	LGPL21+

USES=		linux:rl9
USE_LINUX=	alsalib
USE_LINUX_RPM=	yes

LIB_DISTNAMES=	${PORTNAME}${PKGNAMESUFFIX}-${DISTVERSIONFULL}

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/usr/include \
		${STAGEDIR}${PREFIX}/usr/share/doc

.include <bsd.port.mk>
