PORTNAME=	gitqlient
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.3
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
GH_TAGNAME=	06da655529e288ccd354c08092c21984352e0400:widget \
		36cde545bf3554589b79f6afb2360eb0f80b9f80:logger \
		c400e91ec23317714a55ccf7d7cebe6cafa559f1:aux \
		62f9899415d8b20e2c2814d666536b75dd06c890:git
GH_SUBDIR=	src/QPinnableTabWidget:widget \
		src/QLogger:logger \
		src/AuxiliarCustomWidgets:aux \
		src/git:git

QMAKE_SOURCE_PATH=	${WRKSRC}/GitQlient.pro

.include <bsd.port.mk>
