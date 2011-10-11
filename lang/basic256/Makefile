# New ports collection makefile for:	BASIC256
# Date created:                Aug 17 2011
# Whom:                        Fernando Apesteguia <fernando.apesteguia@gmail.com>
#
# $FreeBSD$

PORTNAME=		basic256
PORTVERSION=		0.9.6.66
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kidbasic/basic256
DISTNAME=		${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		fernando.apesteguia@gmail.com
COMMENT=		An easy to use BASIC language and IDE for education

BUILD_DEPENDS=		espeak:${PORTSDIR}/audio/espeak
BUILD_DEPENDS+=		sqlite3:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS+=		qmake-qt4:${PORTSDIR}/devel/qmake4

WRKSRC=			${WRKDIR}

USE_SDL=		sdl mixer

USE_QT_VER=		4
QT_COMPONENTS= 		corelib gui network xml webkit moc_build qmake_build rcc_build uic_build

USE_DOS2UNIX=		yes

HAS_CONFIGURE=		yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${QMAKE} "PREFIX=${PREFIX}" BASIC256.pro

.include <bsd.port.mk>
