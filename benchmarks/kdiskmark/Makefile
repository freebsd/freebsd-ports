PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	2.3.0
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
		core gui widgets
USE_KDE=	ecm_build

OPTIONS_DEFINE=	CLEARCACHE KF5AUTH
KF5AUTH_IMPLIES=	CLEARCACHE
OPTIONS_SUB=	yes

CLEARCACHE_DESC=	Cache clearing functionality
KF5AUTH_DESC=		KF5Auth cache clearing helper

CLEARCACHE_CMAKE_OFF=	-DBUILD_WITH_PAGECACHE_CLEARING_SUPPORT:BOOL=OFF

KF5AUTH_CMAKE_OFF=	-DPERFORM_PAGECACHE_CLEARING_USING_KF5AUTH:BOOL=OFF
KF5AUTH_USE=		KDE=auth,coreaddons

post-patch:
	@${REINPLACE_CMD} -e '/--ioengine=/s,libaio,posixaio,' \
		${WRKSRC}/src/benchmark.cpp

.include <bsd.port.mk>
