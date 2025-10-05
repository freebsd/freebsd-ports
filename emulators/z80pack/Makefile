PORTNAME=	z80pack
DISTVERSION=	1.38
CATEGORIES=	emulators

MAINTAINER=	se@FreeBSD.org
COMMENT=	Complete CP/M-80 emulator
WWW=		https://www.icl1900.co.uk/unix4fun/z80pack/

CONFLICTS_INSTALL=	hextools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gl gmake jpeg
USE_GL=		gl glu

USE_GITHUB=	yes
GH_ACCOUNT=	udo-munk

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
		cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
