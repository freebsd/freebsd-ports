PORTNAME=	gitqlient
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.1
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
		d1ed24e080521a239d5d5e2c2347fe211f0f3e4f:logger \
		f86e72abd442f73b1e3b10ac922908d03444f115:aux \
		9166fa0226666fda39f3efc10394bc730286ed9d:git
GH_SUBDIR=	src/QPinnableTabWidget:widget \
		src/QLogger:logger \
		src/AuxiliarCustomWidgets:aux \
		src/git:git

QMAKE_SOURCE_PATH=	${WRKSRC}/GitQlient.pro

.include <bsd.port.mk>
