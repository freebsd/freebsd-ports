# $FreeBSD$

PORTNAME=	pixen
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://download.gna.org/gsimageapps/
DISTNAME=	Pixen-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics editing software for small-scale pictures for GNUstep

LICENSE=	MIT

USE_BZIP2=	yes
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

ADDITIONAL_OBJCFLAGS+=	-Dlog2=logb

NO_STAGE=	yes
.include <bsd.port.mk>
