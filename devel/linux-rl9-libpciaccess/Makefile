PORTNAME=	libpciaccess
PORTVERSION=	0.16
DISTVERSIONSUFFIX=	-7.el9
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Generic PCI access library (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.freedesktop.org/wiki/Software/xlibs/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
