PORTNAME=	cairo
PORTVERSION=	0.6.4
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Objective Caml binding for the Cairo library
WWW=		https://github.com/Chris00/ocaml-cairo

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune:devel/ocaml-dune
LIB_DEPENDS+=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gnome pkgconfig
USE_GNOME=	cairo
USE_OCAML=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	Chris00
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

DOCSDIR=	${OCAML_DOCSDIR}/cairo2
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	cd ${BUILD_WRKSRC} && dune build --verbose -j ${MAKE_JOBS_NUMBER} -p cairo2

do-install:
	cd ${INSTALL_WRKSRC} && dune install --destdir=${STAGEDIR} \
		--libdir=${PREFIX}/${OCAML_SITELIBDIR} cairo2

post-install-EXAMPLES-on:
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
