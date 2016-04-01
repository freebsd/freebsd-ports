# $FreeBSD$

PORTNAME=	mtdev
PORTVERSION=	1.1.5
CATEGORIES=	devel
MASTER_SITES=	http://bitmath.org/code/${PORTNAME}/
PKGNAMEPREFIX=	lib

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Multitouch Protocol Translation Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>=1.0.20110603:multimedia/v4l_compat
RUN_DEPENDS=	v4l_compat>=1.0.20110603:multimedia/v4l_compat

USES=		libtool pathfix tar:bz2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include # v4l_compat
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
