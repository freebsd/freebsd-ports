PORTNAME=	ragel
PORTVERSION=	6.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.colm.net/files/${PORTNAME}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code
WWW=		http://www.complang.org/ragel/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=	gmake

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	TEXDOCS EXAMPLES
OPTIONS_SUB=	yes

TEXDOCS_DESC=	Build pdf documentation (requires LaTeX)

TEXDOCS_BROKEN=	Does not build with TeXLive 2023 or later
TEXDOCS_BUILD_DEPENDS=	fig2dev:print/transfig
TEXDOCS_USES=		tex
TEXDOCS_USE=		TEX=latex:build
TEXDOCS_CONFIGURE_ENABLE=	manual

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/test; ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

do-install-TEXDOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
