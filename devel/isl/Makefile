# Created by: Gea-Suan Lin <gslin@gslin.org>

PORTNAME=	isl
PORTVERSION=	0.24
CATEGORIES=	devel math
MASTER_SITES=	http://isl.gforge.inria.fr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integer Set Library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgmp.so:math/gmp

USES=		libtool pkgconfig tar:xz
CONFIGURE_ARGS=	--with-gmp-prefix=${LOCALBASE}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
