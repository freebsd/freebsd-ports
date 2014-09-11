# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.4.1
PORTREVISION=	7
CATEGORIES=	databases kde
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:C,(^[[:digit:]]\.[[:digit:]]).*,\1,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

USES=		cmake shared-mime-info tar:bzip2
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		webkit

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
