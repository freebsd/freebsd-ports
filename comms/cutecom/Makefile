# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=		cutecom
DISTVERSIONPREFIX=	v
DISTVERSION=		0.45.0
CATEGORIES=		comms

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Graphical serial terminal for embedded programming

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lsz:comms/lrzsz

USES=		cmake
USE_QT5=	buildtools_build core gui qmake_build serialport widgets
USE_GITHUB=	yes
GH_ACCOUNT=	neundorf

PLIST_FILES=	bin/cutecom

.include <bsd.port.mk>
