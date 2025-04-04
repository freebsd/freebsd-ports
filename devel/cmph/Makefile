PORTNAME=	cmph
DISTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	https://github.com/bonitao/cmph/releases/download/v${DISTVERSION}/

MAINTAINER=	jessekempf@gmail.com
COMMENT=	Minimal perfect hashes for C
WWW=		https://cmph.sourceforge.net/

LICENSE=	LGPL21 MPL11
LICENSE_COMB=	dual
LICENSE_FILE_LGPL21=	${WRKSRC}/LGPL-2
LICENSE_FILE_MPL11=	${WRKSRC}/MPL-1.1

USES=		libtool pathfix
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcmph.so.0.0.0

.include <bsd.port.mk>
