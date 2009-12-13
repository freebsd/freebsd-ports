# New ports collection makefile for:	mehdiaplayer
# Date created:		2009-11-12
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	mehdiaplayer
PORTVERSION=	0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	A simple media player using Qt/Phonon

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build \
		rcc_build phonon

QMAKE_PRO=	${PORTNAME}.pro

WRKSRC=		${WRKDIR}/dev

PLIST_FILES=	bin/${PORTNAME}

do-configure:
	cd ${WRKSRC} && ${QMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
