# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-eval
PORTVERSION=	0.138
PORTREVISION=	2
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/pokersource/sources/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION:E}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python adaptor for the poker-eval toolkit

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

BROKEN=		unfetchable

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoker-eval.so:games/poker-eval

USES=		autoreconf libtool pathfix pkgconfig python:2.7
USE_PYTHON=	flavors
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	PYTHON=""

PLIST_SUB=	PYVER=${PYTHON_VER:S/./_/}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_pokereval_2_7.so.1.0.0

test:
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
