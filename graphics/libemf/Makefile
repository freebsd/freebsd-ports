PORTNAME=	libEMF
PORTVERSION=	1.0.13
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	libemf-${DISTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Enhanced Metafile Library

LICENSE=	LGPL21

BROKEN_riscv64=		fails to build: ../include/libEMF/wine/winnt.h:77:3: Unknown CPU architecture

OPTIONS_DEFINE=	DOCS

USES=		cpe libtool
CPE_VENDOR=	${PORTNAME:tl}_project

GNU_CONFIGURE=	yes
TEST_TARGET=	check

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
