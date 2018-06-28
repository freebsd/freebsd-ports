# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.6.2
PORTREVISION=	4
CATEGORIES=	databases kde
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4 \
		libqca.so:devel/qca@qt4 \
		libqoauth.so:net/qoauth

USES=		cmake gettext iconv kde:4 qt:4 shared-mime-info tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	kdelibs automoc4
USE_QT=		qmake_build moc_build uic_build rcc_build \
		webkit
USE_LDCONFIG=	yes

.include <bsd.port.mk>
