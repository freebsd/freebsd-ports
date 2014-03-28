# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	leveldb
PORTVERSION=	0.1.20130428
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	LOCAL/sunpoet
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py-${PORTNAME}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Thread-safe Python binding for LevelDB

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libleveldb.so:${PORTSDIR}/databases/leveldb

PYDISTUTILS_AUTOPLIST=	yes
USE_PYDISTUTILS=yes
USE_PYTHON=	yes
USES=		tar:xz

post-patch:
	@${REINPLACE_CMD} \
		-e "s|^\(extra_compile_args = \).*$$|\1\['-I${LOCALBASE}/include'\]|" \
		-e "s|^\(extra_link_args = \).*$$|\1\['-L${LOCALBASE}/lib', '-lleveldb'\]|" \
			${WRKSRC}/${PYSETUP}

.include <bsd.port.mk>
