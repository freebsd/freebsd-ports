# Created by: Gvozdikov Veniamin <g.veniamin@googlemail.com>
# $FreeBSD$

PORTNAME=	mehdiaplayer
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Simple media player using Qt/Phonon

BROKEN=		Unfetchable (google code has gone away)

USES=		tar:bzip2 qmake
USE_QT4=	gui xml uic_build moc_build \
		rcc_build phonon

WRKSRC=		${WRKDIR}/dev

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
