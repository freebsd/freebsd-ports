# ex:ts=8
# New ports collection makefile for:	fastdb
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fastdb
PORTVERSION=	2.51
PORTCOMMENT=	Main Memory Relational Database Management System
CATEGORIES=	databases
MASTER_SITES=	http://www.garret.ru/~knizhnik/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKE_ENV=	OSTYPE="${OPSYS:L}" \
		PREFIX="${PREFIX}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	makefile
INSTALLS_SHLIB=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FastDB.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
