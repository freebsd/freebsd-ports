# $FreeBSD$

PORTNAME=	dsbmixer
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	http://freeshell.de/~mk/download/

MAINTAINER=	mk@nic-nac-project.org
COMMENT=	Tabbed Qt mixer for FreeBSD

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	dsbwrtsysctl:sysutils/dsbwrtsysctl

USES=		tar:tgz qmake

USE_GL=		gl
USE_QT5=	buildtools_build core gui linguisttools_build widgets

QMAKE_ARGS=	PORTS=1

OPTIONS_DEFINE=	DEVD
OPTIONS_DEFAULT=DEVD

DEVD_DESC=	Add new USB audio devices at runtime
DEVD_MAKE_ARGS_OFF=	-DWITHOUT_DEVD

.include <bsd.port.mk>
