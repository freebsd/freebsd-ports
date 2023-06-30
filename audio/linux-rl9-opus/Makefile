PORTNAME=	opus
PORTVERSION=	1.3.1
DISTVERSIONSUFFIX=	-10.el9
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	IETF audio codec (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://opus-codec.org/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
