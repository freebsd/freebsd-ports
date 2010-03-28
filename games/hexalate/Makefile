# New ports collection makefile for:	hexalate
# Date created:		09 Apr 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hexalate
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gottcode.org/${PORTNAME}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A color matching game

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui moc_build qmake_build rcc_build
WANT_GNOME=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes
QMAKEFLAGS+=	PREFIX=${PREFIX}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} ${PORTNAME}.pro

.include <bsd.port.mk>
