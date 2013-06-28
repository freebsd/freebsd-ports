# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fastdb
PORTVERSION=	3.73
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Main Memory Relational Database Management System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
MAKE_ENV=	OSTYPE="${OPSYS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
MAKEFILE=	makefile
USE_LDCONFIG=	yes
USE_DOS2UNIX=	${MAKEFILE}

PORTDOCS=	FastDB.htm

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FastDB.htm ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
