# ex:ts=8
# New ports collection makefile for:	fastdb
# Date created:			Mar 2, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fastdb
PORTVERSION=	3.53
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

PORTDOCS=	FastDB.htm

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FastDB.htm ${DOCSDIR}
.endif

post-patch:
.if ${OSVERSION} < 601105
	${REINPLACE_CMD} -e 's|^#define HAVE_GETHOSTBYNAME_R||' ${WRKSRC}/inc/config.h
.endif

.include <bsd.port.post.mk>
