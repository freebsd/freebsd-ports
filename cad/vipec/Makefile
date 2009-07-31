# ex:ts=8
# New ports collection makefile for:	vipec
# Date created:			April 3, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vipec
PORTVERSION=	3.2.0
PORTREVISION=	5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ViPEC-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyze high frequency, linear electrical networks

WRKSRC=		${WRKDIR}/${DISTNAME}/src

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
USE_GMAKE=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}" VIPECHOME="${DATADIR}"

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ vipec.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../vipec ${PREFIX}/bin/vipec
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/../vipec.cfg ${DATADIR}
	@${MKDIR} ${DATADIR}/ckt
	${INSTALL_DATA} ${WRKSRC}/../ckt/*.* ${DATADIR}/ckt
	@${MKDIR} ${DATADIR}/help
	${INSTALL_DATA} ${WRKSRC}/../help/*.* ${DATADIR}/help
	@${MKDIR} ${DATADIR}/help/models
	${INSTALL_DATA} ${WRKSRC}/../help/models/*.* ${DATADIR}/help/models
	@${MKDIR} ${DATADIR}/messages
	${INSTALL_DATA} ${WRKSRC}/../messages/*.qm ${DATADIR}/messages

.include <bsd.port.mk>
