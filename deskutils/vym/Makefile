PORTNAME=	vym
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
PORTREVISION=	0
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	VYM is a tool to generate and manipulate mind maps
WWW=		https://sourceforge.net/projects/vym/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libcups.so:print/cups
RUN_DEPENDS=	bash:shells/bash \
		zip:archivers/zip

USES=		cmake desktop-file-utils gl qt:6 shared-mime-info shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	insilmaril

USE_GL=		opengl
USE_QT=		base declarative svg translations

SHEBANG_FILES=	scripts/vivym scripts/vym-addmail.rb

CMAKE_ARGS=	-DCMAKE_INSTALL_DATAROOTDIR:PATH="${PREFIX}/share" \
		-DCMAKE_INSTALL_MANDIR:PATH="share/man/man1"

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	VYM_DOCS
DOCS_CMAKE_ON=		-DCMAKE_INSTALL_DOCDIR:PATH="${DOCSDIR}" \
			-DDOCSDIR:PATH="${DOCSDIR}"

post-patch:
	${REINPLACE_CMD} -e 's:/usr/\(bin/zip\):${PREFIX}/\1:1' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
