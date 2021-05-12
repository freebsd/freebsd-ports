# Created by: ijliao

PORTNAME=	ragel
PORTVERSION=	6.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.colm.net/files/${PORTNAME}/

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=	gmake
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	TEXDOCS EXAMPLES
OPTIONS_SUB=	yes
TEXDOCS_CONFIGURE_ENABLE=	manual
TEXDOCS_DESC=	Build pdf documentation (requires LaTeX)
TEXDOCS_USE=		TEX=latex:build
TEXDOCS_BUILD_DEPENDS=	fig2dev:print/transfig

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-TEXDOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/test; ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
