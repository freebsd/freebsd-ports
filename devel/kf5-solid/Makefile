# Created by: tcberner
# $FreeBSD$

PORTNAME=	solid
PORTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 hardware integration and detection

USES=		bison cmake:outsource compiler:c++11-lib kde:5 tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build concurrent core dbus gui linguisttools \
		network qmake_build qml testlib widgets xml

.include <bsd.port.pre.mk>
# Flex on FreeBSD 9 and older 10 is too old
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000033
BUILD_DEPENDS+=	${LOCALBASE}/bin/flex:textproc/flex
.endif

.include <bsd.port.post.mk>
