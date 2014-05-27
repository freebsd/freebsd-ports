# Created by: Sergey A. Osokin <osa@FreeBSD.org.ru>
# $FreeBSD$

PORTNAME=	gigabase
PORTVERSION=	3.86
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.garret.ru/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-Relational Database Management System

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		dos2unix gmake
DOS2UNIX_FILES=	Makefile.in
USE_AUTOTOOLS=	libtool
CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
