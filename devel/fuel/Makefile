# Created by: Hakisho Nukama <nukama@gmail.com>
# $FreeBSD$

PORTNAME=	fuel
DISTVERSION=	0.9.6
CATEGORIES=	devel
MASTER_SITES=	https://fuel-scm.googlecode.com/files/

MAINTAINER=	nukama+maintainer@gmail.com
COMMENT=	GUI front-end to fossil SCM tool

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/bin/fossil:${PORTSDIR}/devel/fossil

USE_QT4=	corelib gui \
		qmake_build moc_build rcc_build uic_build

HAS_CONFIGURE=	yes

PLIST_FILES+=	bin/Fuel

NO_STAGE=	yes
do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Fuel ${PREFIX}/bin/Fuel

.include <bsd.port.mk>
