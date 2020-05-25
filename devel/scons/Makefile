# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	scons
PORTVERSION=	3.1.2
CATEGORIES=	devel python
MASTER_SITES=	SF
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Build tool alternative to make

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	gm4:devel/m4

USES=		python shebangfix
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

PLIST_SUB=	SCONS_VER=${PORTVERSION}

SHEBANG_FILES=	script/scons*

post-patch:
	@${REINPLACE_CMD} -e 's|distutils\(\.command\.install\)$$|setuptools\1|; s|distutils\(\.command\.install\.\)|setuptools\1|' ${WRKSRC}/setup.py
	@${FIND} ${WRKSRC} -name '*.orig' -delete

.include <bsd.port.pre.mk>

PYDISTUTILS_INSTALLARGS+=	--standard-lib

.include <bsd.port.post.mk>
