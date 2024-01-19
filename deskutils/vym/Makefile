PORTNAME=	vym
DISTVERSIONPREFIX=	v
DISTVERSION=	2.9.22
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	VYM is a tool to generate and manipulate mind maps
WWW=		https://sourceforge.net/projects/vym/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash \
		zip:archivers/zip

USES=		cmake desktop-file-utils ninja:build qmake qt:5 \
		shared-mime-info shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	insilmaril

USE_QT=		buildtools core dbus gui linguisttools network printsupport \
		qdbus script svg widgets xml

SHEBANG_FILES=	scripts/vivym scripts/vym-addmail.rb

CMAKE_ARGS=	-DCMAKE_INSTALL_DATAROOTDIR:PATH="${STAGEDIR}${DATADIR}" \
		-DCMAKE_INSTALL_DOCDIR:PATH="${STAGEDIR}${DOCSDIR}" \
		-DCMAKE_INSTALL_MANDIR:PATH="${STAGEDIR}${PREFIX}/share/man/man1" \
		-DDATADIR:PATH="${DATADIR}" \
		-DDOCSDIR:PATH="${DOCSDIR}"
CMAKE_INSTALL_PREFIX=	${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS

DOCS_CMAKE_BOOL=	VYM_DOCS

post-patch:
	${REINPLACE_CMD} -e 's:/usr/\(bin/zip\):${PREFIX}/\1:1' \
		${WRKSRC}/src/main.cpp

.include <bsd.port.mk>
