PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	3.0.0
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical HDD/SSD benchmarking tool

LICENSE=	GPLv3

RUN_DEPENDS=	fio:benchmarks/fio

USE_GITHUB=	yes
GH_ACCOUNT=	JonMagon
GH_PROJECT=	KDiskMark

USES=		cmake compiler:c++11-lang kde:5 qt:5
USE_QT=		buildtools_build linguisttools_build qmake_build \
		dbus core gui widgets
USE_KDE=	ecm_build auth coreaddons

post-patch:
	@${REINPLACE_CMD} -e '/--ioengine=/s,libaio,posixaio,' \
		${WRKSRC}/src/helper.cpp

.include <bsd.port.mk>
