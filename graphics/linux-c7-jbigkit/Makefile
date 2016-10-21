# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	jbigkit
PORTVERSION=	2.0
CATEGORIES=	graphics linux
LIB_DISTFILES=	${PORTNAME}-libs-${PORTVERSION}-${RPMVERSION}${EXTRACT_SUFX}
SRC_DISTFILES=	${DISTNAME}${SRC_SUFX}:SOURCE

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Lossless compression for bi-level images (Linux CentOS ${LINUX_DIST_VER})

RPMVERSION=	11.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-libs-${PORTVERSION}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
