# New ports collection makefile for:	QTK - QuickTk
# Date created:		10 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	qtk
PORTVERSION=	0.50
CATEGORIES=	devel tk82
MASTER_SITES=	http://www.jump.net/~brooke/qtk/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A neat development tool for various languages

RUN_DEPENDS=	${LOCALBASE}/bin/wish8.2:${PORTSDIR}/x11-toolkits/tk82

PLIST_FILES=	bin/qtk
USE_REINPLACE=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_X_PREFIX=	yes

WISH=		${LOCALBASE}/bin/wish8.2

do-configure:
	@${REINPLACE_CMD} \
		-e 's|/usr/bin/wish|${WISH}|;' \
		-e 's|keepnewline wish|keepnewline ${WISH}|' ${WRKSRC}/qtk

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qtk ${PREFIX}/bin

.include <bsd.port.mk>
