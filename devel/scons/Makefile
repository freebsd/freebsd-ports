# Created by: Peter Haight <peterh@sapros.com>
# $FreeBSD$

PORTNAME=	scons
PORTVERSION=	2.5.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Build tool alternative to make

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	gm4:devel/m4

USES=		python:2 shebangfix
SHEBANG_FILES=	script/scons
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

PLIST_SUB=	SCONS_VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} \
		-e 's,distutils\.command\.install$$,setuptools\.command\.install,' \
		-e 's,distutils\.command\.install\.,setuptools\.command\.install\.,' \
		${WRKSRC}/setup.py
	@${FIND} ${WRKSRC} -name \*.orig -delete

.include <bsd.port.mk>
