# $FreeBSD$

PORTNAME=	bats-core
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	lifanov@FreeBSD.org
COMMENT=	Bash automated testing system

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
SHEBANG_FILES=	${SCRIPTS:S/^/libexec\/${PORTNAME}\//}

USE_GITHUB=	yes

NO_BUILD=	yes
NO_ARCH=	yes

SCRIPTS=	bats \
		bats-exec-suite \
		bats-exec-test \
		bats-format-tap-stream \
		bats-preprocess

PLIST_FILES=	${SCRIPTS:S/^/libexec\/${PORTNAME}\//} \
		bin/bats \
		man/man1/bats.1.gz \
		man/man7/bats.7.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for f in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/libexec/${PORTNAME}/${f} \
		${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/${f}
.endfor
	${RLN} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}/bats \
		${STAGEDIR}${PREFIX}/bin/bats
	${INSTALL_MAN} ${WRKSRC}/man/bats.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/bats.7 ${STAGEDIR}${MAN7PREFIX}/man/man7

.include <bsd.port.mk>
