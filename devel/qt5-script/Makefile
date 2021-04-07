PORTNAME=	script
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4-compatible scripting module

USES=		compiler:c++11-lang qmake qt-dist:5,script
USE_QT=		core buildtools_build
# Keep make(1) from descending into src/script/obj/ (qmake:outsource
# doesn't work).
MAKE_ENV=	MAKEOBJDIR=.

post-patch:
	@${REINPLACE_CMD} -e '/scripttools/ d' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
