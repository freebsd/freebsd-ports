# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-eval
PORTVERSION=	0.138
PORTREVISION=	1
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/pokersource/sources/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION:E}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python adaptor for the poker-eval toolkit

LIB_DEPENDS=	libpoker-eval.so:${PORTSDIR}/games/poker-eval

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool pkgconfig python:2
USE_AUTOTOOLS=	aclocal autoconf automake
ACLOCAL_ARGS=	-I config
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	PYTHON=""

PLIST_SUB=	PYVER=${PYTHON_VER:S/./_/}

post-configure:
	@${INSTALL_SCRIPT} ${AUTOMAKE_DIR}/py-compile ${WRKSRC}/config

test:
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
