# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-eval
PORTVERSION=	0.138
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/pokersource/sources/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION:E}.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python adaptor for the poker-eval toolkit

LIB_DEPENDS=	poker-eval.1:${PORTSDIR}/games/poker-eval

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_PYTHON=	2.5-2.7
USE_AUTOTOOLS=	aclocal autoconf automake libtool
ACLOCAL_ARGS=	-I config
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ARGS=	PYTHON=""
MAKE_JOBS_SAFE=	yes

PLIST_SUB=	PYVER=${_PYTHON_VERSION:S/./_/}

post-configure:
	@${INSTALL_SCRIPT} ${AUTOMAKE_DIR}/py-compile ${WRKSRC}/config

test:
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
