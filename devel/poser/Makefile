PORTNAME=		poser
DISTVERSION=		1.2.1
CATEGORIES=		devel
MASTER_SITES=		https://github.com/Zirias/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/download/v${DISTVERSION}

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	C framework for POsix SERvices
WWW=		https://zirias.github.io/poser/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		compiler:c11 gmake pkgconfig tar:xz

USE_LDCONFIG=	yes
MAKEFILE=	GNUmakefile
MAKE_ARGS=	pkgconfigdir=${PREFIX}/libdata/pkgconfig

SOVLIST=	${DISTVERSION:S/./ /g}
SOVMAJ=		${SOVLIST:[1]}
SOVMIN=		${SOVLIST:[2]:C/^$/0/}
SOVREV=		${SOVLIST:[3]:C/^$/0/}
PLIST_SUB=	SOVMAJ=${SOVMAJ} SOVMIN=${SOVMIN} SOVREV=${SOVREV}
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS DOXYGEN TLS
OPTIONS_DEFAULT=	TLS
DOXYGEN_BUILD_DEPENDS=	doxygen>0:devel/doxygen
DOXYGEN_ALL_TARGET=	docs
TLS_USES=		ssl
TLS_MAKE_ARGS_OFF=	WITH_TLS=0

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} html ${STAGEDIR}/${DOCSDIR})

.include <bsd.port.mk>
