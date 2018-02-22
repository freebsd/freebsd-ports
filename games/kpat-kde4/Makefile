# $FreeBSD$

PORTNAME=	kpat
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	games kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource kde:4 shared-mime-info tar:xz
USE_KDE=	kdelibs libkdegames automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

post-patch:
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d' \
		${WRKSRC}/mimetypes/CMakeLists.txt

.include <${.CURDIR}/../kdegames-kde4/Makefile.common>
.include <bsd.port.mk>
