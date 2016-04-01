# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	fuel
DISTVERSION=	0.9.6
CATEGORIES=	devel
MASTER_SITES=	https://fuel-scm.googlecode.com/files/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	GUI front-end to fossil SCM tool

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/fossil:devel/fossil

USES=		qmake
USE_QT4=	corelib gui \
		moc_build rcc_build uic_build

PLIST_FILES=	bin/Fuel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Fuel ${STAGEDIR}${PREFIX}/bin/Fuel

.include <bsd.port.mk>
