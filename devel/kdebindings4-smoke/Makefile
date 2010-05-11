# New ports collection makefile for:	kdebindings4-smoke
# Date created:		2008-08-19
# Whom:			Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kdebindings
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SMOKE bindings for Qt/KDE

LIB_DEPENDS=	qscintilla2.5:${PORTSDIR}/devel/qscintilla2 \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		okularcore.1:${PORTSDIR}/graphics/kdegraphics4

BINDLANG=	smoke

QT_COMPONENTS=	multimedia
USE_KDE4=	pimlibs
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

BUILD_WRKSRC=	${WRKSRC}/${BINDLANG}

.include "${.CURDIR}/../../devel/kdebindings4/files/Makefile.kdebindings"
.include <bsd.port.mk>
