PORTNAME=	libtiff
PORTVERSION=	4.4.0
DISTVERSIONSUFFIX=	-12.el9_4.1
PORTREVISION=	4
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library routines for working with TIFF images (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://www.simplesystems.org/libtiff/

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	jbigkit jpeg webp
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/tiff/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
