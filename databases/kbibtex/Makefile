# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	databases kde
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:C,(^[[:digit:]]\.[[:digit:]]).*,\1,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4 \
		libqca.so:${PORTSDIR}/devel/qca \
		libqoauth.so:${PORTSDIR}/net/qoauth

USES=		cmake iconv shared-mime-info tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		webkit
USE_LDCONFIG=	yes

.include <bsd.port.mk>
