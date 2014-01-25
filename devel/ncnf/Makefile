# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ncnf
PORTVERSION=	3.0.1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic configuration management library

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS=	libstrfunc.so:${PORTSDIR}/devel/libstrfunc

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	YES
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
