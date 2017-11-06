# Created by: ijliao
# $FreeBSD$

PORTNAME=	gnucap
DISTVERSION=	2009-12-07
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.gnucap.org/devel/ \
		http://www.gnucap.org/devel/archive/

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

READLINE_USES=		readline
READLINE_CONFIGURE_OFF=	--with-readline=no

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
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/acs-tutorial ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/history ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/relnotes.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/whatisit ${STAGEDIR}${DOCSDIR}
post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/runall ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.ckt ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.doc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
