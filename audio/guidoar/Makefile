# $FreeBSD$

PORTNAME=	guidoar
PORTVERSION=	g20210127
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library to browse, transform and manipulate Guido scores

LICENSE=	MPL20

BUILD_DEPENDS=	cmake:devel/cmake

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TAGNAME=	cf5681a

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/build

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libguidoar.so.1.00

.include <bsd.port.mk>
