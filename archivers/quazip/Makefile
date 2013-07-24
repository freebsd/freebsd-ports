# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quazip
PORTVERSION=	0.5.1
#PORTREVISION=	0
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Qt/C++ wrapper for ZIP/UNZIP package

LICENSE=	LGPL21

BROKEN=		Does not build

QMAKE_ARGS=	PREFIX=${PREFIX} ${QMAKE_PRO}
QMAKE_PRO=	${WRKSRC}/${PORTNAME}.pro

USE_LDCONFIG=	yes
USE_QT4=	corelib moc_build qtestlib qmake_build

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

.include <bsd.port.mk>
