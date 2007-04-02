# New ports collection makefile for:	tkMOO
# Date created:		20 Jan 2000
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	tkmoo
PORTVERSION=	0.3.32
PORTREVISION=	1
CATEGORIES=	games tk84
MASTER_SITES=	http://www.awns.com/tkMOO-light/Source/
DISTNAME=	tkMOO-light-${PORTVERSION}

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	Tk-based M** client with scripting support

USE_TK_RUN=	yes
MAKE_ENV+=	TKMOO_LIB_DIR="${DATADIR}" \
		TKMOO_BIN_DIR="${PREFIX}/bin" WISH8.3="${WISH}"

do-install:
	@${MKDIR} ${DATADIR}/plugins
	@${INSTALL_DATA} ${WRKSRC}/plugins/* ${DATADIR}/plugins
	@${INSTALL_SCRIPT} ${WRKSRC}/tkMOO-lite ${PREFIX}/bin/tkmoo

.include <bsd.port.mk>
