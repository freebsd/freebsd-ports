# ex:ts=8
# New ports collection makefile for:	poco-ssl
# Date created:			Jan 28, 2007
# Whom:				wes
#
# $FreeBSD$
#

PORTNAME=	poco
PORTVERSION=	1.4.1
CATEGORIES=	devel net
MASTER_SITES=	SF/${PORTNAME}/sources/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	-ssl
DISTNAME=	poco-${PORTVERSION}-all

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Portable Components library with NetSSL library

LIB_DEPENDS=	odbc:${PORTSDIR}/databases/unixODBC

CONFLICTS=	poco-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

USE_MYSQL=	yes
USE_SQLITE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/Data/ODBC/Makefile \
		${WRKSRC}/Data/MySQL/Makefile \
		${WRKSRC}/Data/ODBC/testsuite/Makefile \
		${WRKSRC}/Data/MySQL/testsuite/Makefile

.include <bsd.port.mk>
