# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libechonest
PORTVERSION=	2.0.1
#PORTREVISION=	0
CATEGORIES=	audio

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Collection of C++/Qt classes designed to use the APIs of The Echo Nest

LICENSE=	GPLv2

LIB_DEPENDS=	qjson:${PORTSDIR}/devel/qjson

GH_ACCOUNT=	dschmidt
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	master
GH_COMMIT=	f9a55d1

USES=		cmake
USE_PKGCONFIG=	build
USE_GITHUB=	yes
USE_LDCONFIG=	yes

USE_QT4=	qmake_build moc_build network qtestlib rcc_build xml

.include <bsd.port.mk>
