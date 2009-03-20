# New ports collection makefile for:   mysqltuner
# Date created:		09 September 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysqltuner
PORTVERSION=	1.0.0
CATEGORIES=	databases
MASTER_SITES=	http://mysqltuner.com/releases/
DISTFILES=	${PORTNAME}-${PORTVERSION}.pl
EXTRACT_ONLY=

MAINTAINER=	wenheping@gmail.com
COMMENT=	A Script Assist You with MySQL Configuration

USE_PERL=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

.include <bsd.port.pre.mk>
do-install:
	@${CP} ${DISTDIR}/${PORTNAME}-${PORTVERSION}.pl \
		${PREFIX}/bin/${PORTNAME}.pl
	@${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}.pl
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/bin/${PORTNAME}.pl' \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
