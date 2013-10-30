# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kchmviewer
PORTVERSION=	6.0
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt/KDE viewer for CHM files

LIB_DEPENDS=	libchm.so:${PORTSDIR}/misc/chmlib

USES=		cmake
USE_KDE4=	kdeprefix kdelibs automoc4
USE_QT4=	webkit qmake_build moc_build rcc_build uic_build

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/packages/kchmviewer.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
