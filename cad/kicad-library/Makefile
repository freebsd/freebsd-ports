# Created by: Thierry Thomas <thierry@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kicad
PORTVERSION=	4.0.7
CATEGORIES=	cad
PKGNAMESUFFIX=	-library

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Schematic and 3D libraries supported by KiCad team

LICENSE=	GPLv2

DEPRECATED=	KiCad has been upgraded to 5.0.0
EXPIRATION_DATE=2018-10-24

RUN_DEPENDS=	kicad:cad/kicad

CONFLICTS=	kicad-devel-r201*

USE_GITHUB=	yes
GH_ACCOUNT=	KiCad
GH_PROJECT=	kicad-library

USES=		cmake

NO_ARCH=	yes

.include <bsd.port.mk>
