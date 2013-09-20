# Created by: Sergey A. Osokin <osa@FreeBSD.org.ru>
# $FreeBSD$

PORTNAME=	gigabase
PORTVERSION=	3.86
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.garret.ru/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Object-Relational Database Management System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_DOS2UNIX=	Makefile.in
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
