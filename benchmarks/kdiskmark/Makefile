# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	kdiskmark
PORTVERSION=	2.2.0
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Graphical HDD/SSD benchmarking tool

LICENSE=	GPLv3

RUN_DEPENDS=	fio:benchmarks/fio

USE_GITHUB=	yes
GH_ACCOUNT=	JonMagon
GH_PROJECT=	KDiskMark

USES=		cmake kde:5 qt:5
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core gui widgets
USE_KDE=	auth coreaddons

post-patch:
	@${REINPLACE_CMD} -e '/--ioengine=/s,libaio,posixaio,' \
		${WRKSRC}/src/benchmark.cpp
# XXX: disable pagecache flushing by default to avoid "kf.auth: Tried
# to start an invalid action: org.jonmagon.kdiskmark.dropcache" error.
	@${REINPLACE_CMD} -e '908s,true,false,' ${WRKSRC}/src/mainwindow.ui

.include <bsd.port.mk>
