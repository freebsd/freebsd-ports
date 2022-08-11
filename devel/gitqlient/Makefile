PORTNAME=	gitqlient
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	devel

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Graphical interface to git repositories

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang cpe qmake:outsource qt:5
USE_GL+=	gl
USE_QT=		core gui widgets \
		buildtools_build

USE_GITHUB=	yes
GH_ACCOUNT=	francescmm
GH_PROJECT=	GitQlient \
		QPinnableTabWidget:widget \
		QLogger:logger \
		AuxiliarCustomWidgets:aux \
		git:git
GH_TAGNAME=	cc937794e910d0452f0c07b4961c6014a7358831:widget \
		d1ed24e080521a239d5d5e2c2347fe211f0f3e4f:logger \
		835f538b4a79e4d6bb70eef37a32103e7b2a1fd1:aux \
		b62750f4da4b133faff49e6f53950d659b18c948:git
GH_SUBDIR=	src/QPinnableTabWidget:widget \
		src/QLogger:logger \
		src/AuxiliarCustomWidgets:aux \
		src/git:git

QMAKE_SOURCE_PATH=	${WRKSRC}/GitQlient.pro

.include <bsd.port.mk>
