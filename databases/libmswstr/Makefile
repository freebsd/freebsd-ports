PORTNAME=	libmswstr
PORTVERSION=	0.0.1
CATEGORIES=	databases

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Read and parse mdb file indices

# https://github.com/leecher1337/libmswstr/blob/master/COPYING
#DISABLE_LICENSES=	yes
USES=		autoreconf dos2unix libtool
DOS2UNIX_FILES=	mswstr.c nls.h nlstables.h
DOS2UNIX_WRKSRC=	${WRKSRC}/src
USE_GITHUB=	yes
GH_ACCOUNT=	leecher1337
GH_TAGNAME=	5682d51
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
