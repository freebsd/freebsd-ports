# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	databases kde
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:C,(^[[:digit:]]\.[[:digit:]]).*,\1,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

USE_BZIP2=	yes
USES=		cmake
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdelibs kdeprefix automoc4 sharedmime
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		webkit

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
