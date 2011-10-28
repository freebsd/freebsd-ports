# New ports collection makefile for:	py-leveldb
# Date created:		2011-10-04
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	leveldb
PORTVERSION=	0.1.20111024
CATEGORIES=	databases python
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thread-safe Python binding for LevelDB

LIB_DEPENDS=	leveldb:${PORTSDIR}/databases/leveldb

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
USE_XZ=		yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/leveldb.so
PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION:R}-py${PYTHON_VER}.egg-info

post-patch:
	@${REINPLACE_CMD} \
		-e "s|^\(extra_compile_args = \).*$$|\1\['-I${LOCALBASE}/include'\]|" \
		-e "s|^\(extra_link_args = \).*$$|\1\['-L${LOCALBASE}/lib', '-lleveldb'\]|" \
			${WRKSRC}/setup.py

.include <bsd.port.mk>
