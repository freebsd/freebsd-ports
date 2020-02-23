# $FreeBSD$

PORTNAME=	stringtie
DISTVERSION=	2.1.1
CATEGORIES=	biology
MASTER_SITES=	http://ccb.jhu.edu/software/stringtie/dl/

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	Transcript assembly and quantification for RNA-seq

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash \
		curl:ftp/curl

USES=		compiler:c++11-lang gmake
ALL_TARGET=	release
TEST_TARGET=	test

PLIST_FILES=	bin/stringtie

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stringtie ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
