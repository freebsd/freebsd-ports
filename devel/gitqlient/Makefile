PORTNAME=	gitqlient
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
CATEGORIES=	devel

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Graphical interface to git repositories
WWW=		https://francescmm.github.io/GitQlient/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang cpe qmake:outsource qt:5
USE_GL+=	gl
USE_QT=		core gui widgets \
		buildtools:build

USE_GITHUB=	yes
GH_ACCOUNT=	francescmm
GH_PROJECT=	GitQlient \
		QPinnableTabWidget:widget \
		QLogger:logger \
		AuxiliarCustomWidgets:aux \
		git:git
GH_TAGNAME=	40d0a02e5bdf2f49f9ea41ca533093b2808b0140:widget \
		ce2f35bad6440a14802fed6c043323d4227ef9a9:logger \
		f86e72abd442f73b1e3b10ac922908d03444f115:aux \
		fd63515ee55c2f4f0d8ac3969fcddf322964b3ee:git
GH_SUBDIR=	src/QPinnableTabWidget:widget \
		src/QLogger:logger \
		src/AuxiliarCustomWidgets:aux \
		src/git:git

QMAKE_SOURCE_PATH=	${WRKSRC}/GitQlient.pro

.include <bsd.port.mk>
