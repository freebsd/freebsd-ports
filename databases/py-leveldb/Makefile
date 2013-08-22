# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	0.1.20130428
CATEGORIES=	databases python
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thread-safe Python binding for LevelDB

LIB_DEPENDS=	leveldb:${PORTSDIR}/databases/leveldb

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
USE_XZ=		yes

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/leveldb.so
PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION:R}-py${PYTHON_VER}.egg-info

post-patch:
	@${REINPLACE_CMD} \
		-e 's|setuptools|do_not_use_&|' \
		-e "s|^\(extra_compile_args = \).*$$|\1\['-I${LOCALBASE}/include'\]|" \
		-e "s|^\(extra_link_args = \).*$$|\1\['-L${LOCALBASE}/lib', '-lleveldb'\]|" \
			${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
