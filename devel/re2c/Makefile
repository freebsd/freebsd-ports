# Created by: Eivind Eklund <eivind@FreeBSD.org>
# $FreeBSD$

PORTNAME=	re2c
PORTVERSION=	0.14.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}

MAINTAINER=	chalpin@cs.wisc.edu
COMMENT=	Compile regular expression to C (much faster final code than flex)

OPTIONS_DEFINE=	DOCS EXAMPLES

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/re2c \
		man/man1/re2c.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	(cd ${WRKSRC}/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/)

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/)

.include <bsd.port.mk>
