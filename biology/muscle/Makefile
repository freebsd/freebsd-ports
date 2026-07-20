PORTNAME=	muscle
PORTVERSION=	5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	biology

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	MUltiple Sequence Comparison by Log-Expectation
WWW=		https://www.drive5.com/muscle/

LICENSE=	GPLv3

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake
USE_GCC=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rcedgar
ALL_TARGET=	${OPSYS}/${PORTNAME}
BINARY_ALIAS=	g++=g++14
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/muscle

do-install:
	cd ${WRKSRC} && \
	${INSTALL} ${OPSYS}/muscle ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
