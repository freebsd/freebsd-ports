# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tel
PORTVERSION=	0.1.7.1
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	CENKES BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little console-based phone book manager

USE_BZIP2=	yes
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
NO_STAGE=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install ,setuptools\.command\.install ,' \
		${WRKSRC}/appdistutils.py

.include <bsd.port.mk>
