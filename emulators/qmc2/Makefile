# New ports collection makefile for:	qmc2
# Date created:				2007-02-25
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	qmc2
PORTVERSION=	0.1.b8
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Qt 4 based UNIX MAME frontend supporting both XMAME and SDLMAME

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
MAKE_ENV=	QTDIR="${QTDIR}" QMAKE="${QMAKE}" SYSCONFDIR="${PREFIX}/etc"
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	XMAME "Enable support for XMAME instead of SDLMAME" off

.include <bsd.port.pre.mk>

.if defined(WITH_XMAME)
MAKE_ENV+=	SDLMAME=0
RUN_DEPENDS+=	xmame:${PORTSDIR}/emulators/xmame
.else
RUN_DEPENDS+=	sdlmame:${PORTSDIR}/emulators/sdlmame
.endif

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
