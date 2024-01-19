PORTNAME=	lziprecover
PORTVERSION=	1.23
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH/lzip/${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Recovery tool for Lzip compressed data files
WWW=		https://www.nongnu.org/lzip/lziprecover.html

LICENSE=	GPLv2+

USES=		tar:lz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --infodir=${PREFIX}/${INFO_PATH} \
		--mandir=${PREFIX}/share/man CXXFLAGS="${CXXFLAGS}"
TEST_TARGET=	check

INFO=		${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
