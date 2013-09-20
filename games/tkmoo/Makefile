# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	tkmoo
PORTVERSION=	0.3.32
PORTREVISION=	3
CATEGORIES=	games tk
MASTER_SITES=	http://www.awns.com/tkMOO-light/Source/
DISTNAME=	tkMOO-light-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tk-based M** client with scripting support

USE_TK_RUN=	yes
MAKE_ENV+=	TKMOO_LIB_DIR="${DATADIR}" \
		TKMOO_BIN_DIR="${PREFIX}/bin" WISH8.3="${WISH}"

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR}/plugins
	@${INSTALL_DATA} ${WRKSRC}/plugins/* ${DATADIR}/plugins
	@${INSTALL_SCRIPT} ${WRKSRC}/tkMOO-lite ${PREFIX}/bin/tkmoo

.include <bsd.port.mk>
