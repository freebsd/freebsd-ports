PORTNAME=	rudeconfig
PORTVERSION=	5.0.5
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	http://www.rudeserver.com/config/download/

MAINTAINER=	lowmaster@web.de
COMMENT=	Library for handling configuration files, written in C++
WWW=		http://www.rudeserver.com/

USES=		dos2unix libtool
USE_CXXSTD=	c++14
DOS2UNIX_GLOB=	*
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

pre-install:
	${CHMOD} 744 ${WRKSRC}/install-sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librudeconfig.so

.include <bsd.port.mk>
