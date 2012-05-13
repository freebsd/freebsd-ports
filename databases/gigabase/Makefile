# ports collection makefile for:	gigabase
# Date created:			15 August 2000
# Whom:				Sergey A. Osokin <osa@FreeBSD.org.ru>
#
# $FreeBSD$
#

PORTNAME=	gigabase
PORTVERSION=	3.86
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.garret.ru/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Object-Relational Database Management System

BROKEN=		does not patch

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
USE_LDCONFIG=	yes

.include <bsd.port.mk>
