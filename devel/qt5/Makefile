# $FreeBSD$

PORTNAME=	qt5
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform application and UI framework (metaport)

USE_QT5=	${_USE_QT_ALL:Nphonon4:S/$/_run/} # phonon4 is not part of Qt itself.
USES=		metaport

.include <bsd.port.mk>
