# New ports collection makefile for:	QNetChess
# Date created:		2005-03-02
# Whom:			Andrej Zverev <az@inec.ru>
#
# $FreeBSD$
#

PORTNAME=	QNetChess
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.silversoft.net/src/

MAINTAINER=	az@inec.ru
COMMENT=	Qt based chess multiplayer game

MAKEFILE=	Makefile.FreeBSD
LOCALE_FILE=	"${DATADIR}/${PORTNAME}_ru"

USE_BZIP2=	yes
USE_QT_VER=	3
USE_X_PREFIX=	yes

MAKE_ARGS+=	LOCALE_FILE="${LOCALE_FILE}"

PLIST_FILES=	bin/QNetChess %%DATADIR%%/${PORTNAME}_ru.qm
PLIST_DIRS=	%%DATADIR%%

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/QNetChess	${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/${PORTNAME}_ru.qm	${DATADIR}/

.include <bsd.port.mk>
