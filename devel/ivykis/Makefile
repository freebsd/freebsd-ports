PORTNAME=	ivykis
DISTVERSIONPREFIX=	v
DISTVERSION=	0.42.4
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	algernon@madhouse-project.org
COMMENT=	Asynchronous I/O readiness notification library
WWW=		https://github.com/buytenh/ivykis

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	buytenh

INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} -e '/iv_inotify/d' ${WRKSRC}/libivykis.posix.ver

.include <bsd.port.mk>
