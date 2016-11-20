# Created by: Sergey A. Osokin <osa@FreeBSD.org.ru>
# $FreeBSD$

PORTNAME=	gigabase
PORTVERSION=	3.91
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.garret.ru/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Object-Relational Database Management System

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
USES=		autoreconf dos2unix gmake libtool
DOS2UNIX_FILES=	Makefile.in configure.in *.cpp *.h
USE_GCC=	any
USE_LDCONFIG=	yes

post-build:
	${STRIP_CMD} ${WRKSRC}/.libs/*.so

.include <bsd.port.mk>
