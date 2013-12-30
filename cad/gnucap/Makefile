# Created by: ijliao
# $FreeBSD$

PORTNAME=	gnucap
PORTVERSION=	2009.12.07
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.gnucap.org/devel/archive/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU Circuit Analysis Package

LICENSE=	GPLv3

OPTIONS_DEFINE=	READLINE DOCS EXAMPLES
OPTIONS_DEFAULT=READLINE
READLINE_DESC=	Enable readline support

USES=		gmake
GNU_CONFIGURE=	yes

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/gnucap bin/gnucap-modelgen \
		man/man1/gnucap-ibis.1.gz man/man1/gnucap.1.gz

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
.else
CONFIGURE_ARGS+=--with-readline=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc examples||' ${WRKSRC}/Makefile.in
.for i in src/ap_match.cc modelgen/ap_match.cc
	@${REINPLACE_CMD} -e \
		"s:strchr(str2, '|'):const_cast<char*>(strchr(str2, '|')):" \
		${WRKSRC}/${i}
.endfor

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/history ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/relnotes.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/runall ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ckt ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.doc ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
