PORTNAME=	muscle
PORTVERSION=	5.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	MUltiple Sequence Comparison by Log-Expectation
WWW=		https://www.drive5.com/muscle/

LICENSE=	GPLv3

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	rcedgar
ALL_TARGET=	${OPSYS}/${PORTNAME}
WRKSRC_SUBDIR=	src

PLIST_FILES=	bin/muscle

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${OPSYS}/muscle ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
