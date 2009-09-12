# New ports collection makefile for: kile
# Date created:		21 Jun 2002
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	kile
DISTVERSION=	2.1b2
CATEGORIES=	editors kde
MASTER_SITES=	SF/${PORTNAME}/unstable/${PORTNAME}-${DISTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A LaTeX source editor for KDE

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		identify:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdeprefix kdelibs automoc4
MAKE_JOBS_SAFE=	yes

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS=	OKULAR "Use Okular for viewing" on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_OKULAR)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/okular:${PORTSDIR}/graphics/kdegraphics4
.endif

.include <bsd.port.mk>
