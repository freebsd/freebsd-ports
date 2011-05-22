# New ports collection makefile for:   mysqltuner
# Date created:		09 September 2008
# Whom:			Wen heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mysqltuner
PORTVERSION=	1.2.0
CATEGORIES=	databases
MASTER_SITES=	http://mysqltuner.pl/
DISTNAME=	${PORTNAME}.pl
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	A Script Assist You with MySQL Configuration

LICENSE=	GPLv3

USE_PERL=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}.pl

pre-patch:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

.include <bsd.port.pre.mk>
do-install:
	@${CP} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${DISTNAME}
	@${CHMOD} 755 ${PREFIX}/bin/${DISTNAME}
	@${ECHO_CMD} '@exec ${CHMOD} 755 ${PREFIX}/bin/${DISTNAME}.pl' \
		>> ${TMPPLIST}

.include <bsd.port.post.mk>
