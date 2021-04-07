PORTNAME=	pixen
PORTVERSION=	0.1
PORTREVISION=	10
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	Pixen-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics editing software for small-scale pictures for GNUstep

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		tar:bzip2 gnustep
USE_GNUSTEP=	back build

ADDITIONAL_OBJCFLAGS+=	-Dlog2=logb

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/Pixen.app/Pixen

.include <bsd.port.mk>
