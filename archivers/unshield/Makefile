# Created by: Stefan Esser <se@FreeBSD.org>
# $FreeBSD$

PORTNAME=	unshield
PORTVERSION=	1.4
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extract data from InstallShield CAB files

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CFLAGS+=	-fPIC
USE_LDCONFIG=	yes
USES=		cmake pathfix

GH_ACCOUNT=	twogood
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/CMAKE_INSTALL_DATAROOTDIR/ s|DATAROOTDIR|PREFIX|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
