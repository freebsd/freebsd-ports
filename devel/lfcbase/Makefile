PORTNAME=	lfcbase
PORTVERSION=	1.22.1
CATEGORIES=	devel
MASTER_SITES=	http://www.lemke-it.com/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Collection of basic c++ classes, used for databases/cego
WWW=		https://www.lemke-it.com/

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool ncurses
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} 's|-O3||g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
