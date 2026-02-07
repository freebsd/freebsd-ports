PORTNAME=	lfcxml
PORTVERSION=	1.3.9
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	C++ XML library, used for databases/cego
WWW=		https://www.lemke-it.com/

LICENSE=	GPLv3

LIB_DEPENDS=	liblfcbase.so:devel/lfcbase

USES=		libtool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
