# Created by: Tilman Linneweh <arved@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tuxcards
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.tuxcards.de/src/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Tool for managing notes within a hierarchical tree

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_QT4=	gui xml qmake_build moc_build uic_build rcc_build

MAKE_ENV=	QTDIR="${QT_PREFIX}"
PLIST_FILES=	bin/tuxcards

NO_STAGE=	yes
.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} -spec ${QMAKESPEC} tuxcards.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
