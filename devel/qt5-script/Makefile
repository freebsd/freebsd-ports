PORTNAME=	script
PORTVERSION=	${QT5_VERSION}${QT5_KDE_PATCH}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt 4-compatible scripting module

USES=		compiler:c++11-lang perl5 qmake qt-dist:5,script
USE_PERL5=	extract
USE_QT=		core buildtools_build
# Keep make(1) from descending into src/script/obj/ (qmake:outsource
# doesn't work).
MAKE_ENV=	MAKEOBJDIR=.

QT5_VERSION=	5.15.10

post-patch:
	@${REINPLACE_CMD} -e '/scripttools/ d' \
		${WRKSRC}/src/src.pro

.include <bsd.port.mk>
