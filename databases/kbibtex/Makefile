# New ports collection makefile for:	kbibtex
# Date created:				Mon Aug  8 18:43:04 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kbibtex
DISTVERSION=	0.4
CATEGORIES=	databases kde
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:C,(^[[:digit:]]\.[[:digit:]]).*,\1,}/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Bibliography editor for KDE

LIB_DEPENDS=	poppler-qt4.3:${PORTSDIR}/graphics/poppler-qt4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdelibs kdeprefix automoc4 sharedmime
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build uic_build rcc_build \
		webkit
MAKE_JOBS_SAFE=	yes

MAN1=		kbibtex.1

post-patch:
	${REINPLACE_CMD} -e 's,share/man,man,' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
