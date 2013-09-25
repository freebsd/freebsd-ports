# Created by: ijliao
# $FreeBSD$

PORTNAME=	ragel
PORTVERSION=	6.8
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.complang.org/ragel/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Compile regular languages into executable C/C++ code

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=	gmake
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_CONFIGURE_ENABLE=	manual

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build
BUILD_DEPENDS+=	fig2dev:${PORTSDIR}/print/transfig
.endif

post-patch:
	@${REINPLACE_CMD} 's/setiosflags/std::&/' \
		${WRKSRC}/ragel/javacodegen.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ragel/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/test; ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
