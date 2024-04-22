PORTNAME=	${GH_PROJECT:[1]:tl}
PORTVERSION=	3.1.2
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical HDD/SSD benchmarking tool
WWW=		https://github.com/JonMagon/KDiskMark

LICENSE=	GPLv3

LIB_DEPENDS=	libpolkit-qt5-core-1.so:sysutils/polkit-qt-1@qt5
RUN_DEPENDS=	fio:benchmarks/fio

USE_GITHUB=	yes
GH_ACCOUNT=	JonMagon itay-grudev:sa
GH_PROJECT=	KDiskMark SingleApplication:sa
GH_TAGNAME=	f1e1508:sa
GH_SUBDIR=	src/singleapplication:sa

USES=		cmake compiler:c++11-lang kde:5 qt:5
USE_QT=		buildtools:build linguisttools:build qmake:build \
		dbus core gui network widgets
USE_KDE=	ecm:build auth coreaddons

post-patch:
	@${REINPLACE_CMD} -e '/--ioengine=/s,libaio,posixaio,' \
		${WRKSRC}/src/helper.cpp

.include <bsd.port.mk>
