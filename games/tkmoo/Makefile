# New ports collection makefile for:	tkMOO
# Date created:		20 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	tkmoo
PORTVERSION=	0.3.32
CATEGORIES=	games tk83
MASTER_SITES=	http://www.awns.com/tkMOO-light/Source/
DISTNAME=	tkMOO-light-${PORTVERSION}

MAINTAINER=	adam-ports@blacktabby.org

RUN_DEPENDS=	${WISH83}:${PORTSDIR}/x11-toolkits/tk83

WISH83?=	${LOCALBASE}/bin/wish8.3
MAKE_ENV+=	TKMOO_LIB_DIR="${DATADIR}" \
		TKMOO_BIN_DIR="${PREFIX}/bin" WISH8.3="${WISH83}"

do-install:
	@${MKDIR} ${DATADIR}/plugins
	@${INSTALL_DATA} ${WRKSRC}/plugins/* ${DATADIR}/plugins
	@${INSTALL_SCRIPT} ${WRKSRC}/tkMOO-lite ${PREFIX}/bin/tkmoo

.include <bsd.port.mk>
