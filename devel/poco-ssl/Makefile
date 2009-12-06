# ex:ts=8
# New ports collection makefile for:	poco-ssl
# Date created:			Jan 28, 2007
# Whom:				wes
#
# $FreeBSD$
#

PORTNAME=	poco
PORTVERSION=	1.3.6
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-ssl
DISTNAME=	poco-${PORTVERSION}-all

MAINTAINER=	wes@FreeBSD.org
COMMENT=	C++ Portable Components library with NetSSL library
CONFLICTS=	poco-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

USE_MYSQL=	yes
USE_SQLITE=	yes
LIB_DEPENDS=	odbc:${PORTSDIR}/databases/unixODBC

.include <bsd.port.mk>
