# New ports collection makefile for:	qmc2
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qmc2
PORTVERSION=	0.2.b1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Qt 4 based UNIX MAME frontend supporting SDLMAME

RUN_DEPENDS=	sdlmame:${PORTSDIR}/emulators/sdlmame

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
MAKE_ENV=	QTDIR="${QTDIR}" QMAKE="${QMAKE}" SYSCONFDIR="${PREFIX}/etc"
WRKSRC=		${WRKDIR}/${PORTNAME}

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
