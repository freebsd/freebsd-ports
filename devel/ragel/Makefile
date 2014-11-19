# Created by: ijliao
# $FreeBSD$

PORTNAME=	ragel
PORTVERSION=	6.9
CATEGORIES=	devel
MASTER_SITES=	http://www.colm.net/wp-content/uploads/2014/10/ \
		http://www.complang.org/ragel/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=	gmake
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_CONFIGURE_ENABLE=	manual
DOCS_USE=		TEX=latex:build
DOCS_BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/test; ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
