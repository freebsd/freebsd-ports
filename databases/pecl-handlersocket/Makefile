# New ports collection makefile for:	pecl-handlersocket
# Date created:				Dec 16 2010
# Whom:					jnlin@csie.nctu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	handlersocket
PORTVERSION=	0.0.6
CATEGORIES=	databases pear
MASTER_SITES=	http://php-handlersocket.googlecode.com/files/
PKGNAMEPREFIX=	pecl-
DISTNAME=	php-${PORTNAME}-${PORTVERSION}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	A PECL extension for HandlerSocket

BUILD_DEPENDS=	libhsclient>0:${PORTSDIR}/databases/libhsclient

WRKSRC=		${WRKDIR}/php-${PORTNAME}

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-handlersocket=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${EXTRA_LIBS}"

.include <bsd.port.mk>
