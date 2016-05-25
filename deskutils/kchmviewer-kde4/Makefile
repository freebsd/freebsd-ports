# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kchmviewer
PORTVERSION=	7.2
DISTVERSIONSUFFIX=	.1
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDE viewer for CHM files

LIB_DEPENDS=	libchm.so:misc/chmlib \
		libzip.so:archivers/libzip

USES=		cmake:outsource gettext-tools
USE_KDE4=	kdelibs automoc4
USE_QT4=	webkit qmake_build moc_build rcc_build uic_build

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

post-patch:
	${REINPLACE_CMD} 's,/usr/bin/kate,${KDE4_PREFIX}/bin/kate,' \
		${WRKSRC}/src/config.cpp

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/packages/kchmviewer.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
