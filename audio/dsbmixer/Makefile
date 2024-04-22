PORTNAME=	dsbmixer
PORTVERSION=	2.0
CATEGORIES=	audio

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Tabbed Qt mixer for FreeBSD
WWW=		https://github.com/mrclksr/DSBMixer

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dsbwrtsysctl:sysutils/dsbwrtsysctl

USES=		cmake compiler:c++11-lang gl kde:5 qmake qt:5 tar:tgz

USE_GITHUB=	yes
GH_ACCOUNT=	mrclksr
GH_PROJECT=	DSBMixer

USE_GL=		gl
USE_KDE=	notifications
USE_QT=		core dbus gui widgets buildtools:build linguisttools:build \
		qmake:build

CMAKE_ON=	PORTS

MAKE_ENV+=	DESTDIR=${STAGEDIR}

OPTIONS_DEFINE=		DEVD
OPTIONS_DEFAULT=	DEVD

DEVD_DESC=	Add new USB audio devices at runtime
DEVD_CMAKE_OFF=	-DWITHOUT_DEVD:BOOL=true

.include <bsd.port.mk>
