# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qcomicbook
PORTVERSION=	0.9.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://qcomicbook.org/releases/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt-based comic book archive viewer

LICENSE=	GPLv2

LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

USES=		cmake:outsource pkgconfig
USE_QT4=	corelib gui linguisttools_build moc_build qmake_build rcc_build \
		uic_build xml

OPTIONS_DEFINE=	7ZIP ACE RAR ZIP

7ZIP_DESC=	7-Zip (.cb7) comic book archives support
7ZIP_RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

ACE_DESC=	ACE (.cba) comic book archives support
ACE_RUN_DEPENDS=	unace:${PORTSDIR}/archivers/unace

RAR_DESC=	Rar (.cbr) comic book archives support
RAR_RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar

ZIP_DESC=	Zip (.cbz) comic book archives support
ZIP_RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

post-patch:
# fix man install directory
	@${REINPLACE_CMD} -E \
		-e 's|share/man|man|' \
		${WRKSRC}/help/CMakeLists.txt
# fix pixmap location
	@${REINPLACE_CMD} -E \
		-e 's|(qcomicbook.png)|${PREFIX}/share/pixmaps/\1|' \
		${WRKSRC}/data/qcomicbook.desktop

.include <bsd.port.mk>
