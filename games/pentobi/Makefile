PORTNAME=	pentobi
PORTVERSION=	23.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Computer opponent for the board game Blokus
WWW=		https://pentobi.sourceforge.io/ \
		https://github.com/enz/pentobi

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	itstool:textproc/itstool \
		xsltproc:textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

USES=		compiler:c++20-lang cmake desktop-file-utils gettext-tools gnome qt:6 \
		shared-mime-info tar:xz
USE_GNOME=	librsvg2:build
USE_QT=		base declarative tools:build

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	test

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS.md CONTRIBUTING.md NEWS.md \
		README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
