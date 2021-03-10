# Created by: Nicola Stanislao Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flameshot
PORTVERSION=	0.9.0
#PORTREVISION=	0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Powerful yet simple to use screenshot software

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang gl qmake qt:5

CMAKE_INSTALL_PREFIX=	${STAGEDIR}/${PREFIX}

GH_ACCOUNT=	flameshot-org

USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		core dbus gui linguist network svg widgets \
		buildtools_build

post-patch:
	        @${REINPLACE_CMD} -e 's,$${CMAKE_INSTALL_FULL_BINDIR},${LOCALBASE}/bin,1' \
	                ${WRKSRC}/data/dbus/org.flameshot.Flameshot.service.in

.include <bsd.port.mk>
