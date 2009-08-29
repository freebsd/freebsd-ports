# New ports collection makefile for:	qdoc3
# Date created:		2009-08-20
# Whom:			Maxim Ignatenko <gelraen.ua@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	qdoc3
PORTVERSION=	${QT4_VERSION}
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt documentation generator

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build corelib xml
QT_NONSTANDART=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --include '${DISTNAME}/tools/${PORTNAME}'

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=	${WRKDIR}/${DISTNAME}/tools/${PORTNAME}
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} ${PORTNAME}.pro

do-install:
	${INSTALL_PROGRAM} "${WRKSRC}/${PORTNAME}" "${PREFIX}/bin/${PORTNAME}"

.include <bsd.port.mk>
