# Created by: Andriy Gapon <avg@icyb.net.ua>
# $FreeBSD$

PORTNAME=	charmtimetracker
PORTVERSION=	1.11.4
CATEGORIES=	deskutils

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Time tracker

LICENSE=	GPLv2

BROKEN_powerpc64=	fails to compile: cc1plus: unrecognized command line option "-std=c++0x"

USE_GITHUB=	yes
GH_ACCOUNT=	KDAB
GH_PROJECT=	Charm

USES=		cmake
CMAKE_ARGS+=	-DCharm_VERSION:STRING=${PORTVERSION} -DCHARM_FORCE_QT4=true
USE_QT4=	qmake_build moc_build rcc_build uic_build corelib dbus gui \
		network qtestlib script sql sql-sqlite3 xml
USE_XORG=	ice x11 xext xscrnsaver
INSTALLS_ICONS=	yes

PORTDOCS=	ReadMe.txt

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} ${STAGEDIR}${DOCSDIR}/License.txt

.include <bsd.port.mk>
