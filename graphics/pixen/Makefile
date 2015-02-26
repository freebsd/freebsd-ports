# $FreeBSD$

PORTNAME=	pixen
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	Pixen-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics editing software for small-scale pictures for GNUstep

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		tar:bzip2
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

ADDITIONAL_OBJCFLAGS+=	-Dlog2=logb

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/Local/Applications/Pixen.app/Pixen

.include <bsd.port.mk>
