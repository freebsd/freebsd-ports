# ex:ts=8
# New ports collection makefile for:	fastdb
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fastdb
PORTVERSION=	3.15
CATEGORIES=	databases
MASTER_SITES=	http://www.garret.ru/~knizhnik/

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Main Memory Relational Database Management System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKE_ENV=	OSTYPE="${OPSYS}" \
		PREFIX="${PREFIX}" \
		CXX="${CXX}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

PORTDOCS=	FastDB.htm

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FastDB.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
