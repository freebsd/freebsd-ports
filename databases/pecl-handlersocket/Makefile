# Created by: jnlin@csie.nctu.edu.tw
# $FreeBSD$

PORTNAME=	handlersocket
PORTVERSION=	0.3.1
CATEGORIES=	databases pear
MASTER_SITES=	http://php-handlersocket.googlecode.com/files/
PKGNAMEPREFIX=	pecl-
DISTNAME=	php-${PORTNAME}-${PORTVERSION}
DISTFILES=	php-handelrsocket-0.3.1${EXTRACT_SUFX}

MAINTAINER=	jnlin@csie.nctu.edu.tw
COMMENT=	PECL extension for HandlerSocket

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

BUILD_DEPENDS=	libhsclient>0:${PORTSDIR}/databases/libhsclient

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-handlersocket=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${EXTRA_LIBS}

.include <bsd.port.mk>
