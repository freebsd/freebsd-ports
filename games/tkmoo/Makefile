# New ports collection makefile for:	tkMOO
# Date created:		20 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	tkmoo
PORTVERSION=	0.3.23
CATEGORIES=	games tk82
MASTER_SITES=	http://www.awns.com/tkMOO-light/Source/
DISTNAME=	tkMOO-light-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${WISH82}:${PORTSDIR}/x11-toolkits/tk82

WISH82?=	${LOCALBASE}/bin/wish8.2
MAKE_ENV+=	TKMOO_LIB_DIR="${PREFIX}/share/tkmoo" \
		TKMOO_BIN_DIR="${PREFIX}/bin" WISH8.2="${WISH82}"

do-install:
	@${MKDIR} ${PREFIX}/share/tkmoo/plugins
	@${INSTALL_DATA} ${WRKSRC}/plugins/* ${PREFIX}/share/tkmoo/plugins
	@${INSTALL_SCRIPT} ${WRKSRC}/tkMOO-lite ${PREFIX}/bin/tkmoo

.include <bsd.port.mk>
