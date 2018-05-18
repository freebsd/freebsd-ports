# $FreeBSD$

PORTNAME=	linguisttools
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	devel
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt localization tools

USE_QT5=	core xml buildtools_build qml_build
QT_DIST=	tools
USES=		qmake

BUILD_WRKSRC=	${WRKSRC}/src/linguist
INSTALL_WRKSRC=	${WRKSRC}/src/linguist

post-patch:
	@${REINPLACE_CMD} -e '/SUBDIRS.*linguist/ d' \
		${WRKSRC}/src/linguist/linguist.pro

post-install:
.for f in lrelease lupdate
	${INSTALL_MAN} ${WRKSRC}/src/linguist/${f}/${f}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
.endfor

.include <bsd.port.mk>
