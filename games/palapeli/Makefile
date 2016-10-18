# $FreeBSD$

PORTNAME=	palapeli
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource kde:4 shared-mime-info tar:xz
USE_KDE=	kdelibs libkdegames automoc4
USE_QT4=	corelib gui gui \
		moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${WRKSRC}/mime/CMakeLists.txt

.include <${.CURDIR}/../kdegames4/Makefile.common>
.include <bsd.port.mk>
