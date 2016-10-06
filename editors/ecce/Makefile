# Created by: Bob Eager <bob@eager.cx>
# $FreeBSD$

PORTNAME=	ecce
DISTVERSION=	2.9d
CATEGORIES=	editors
MASTER_SITES=	http://www.ml1.org.uk/distfiles/ \
		http://www.ancientgeek.org.uk/distfiles/

MAINTAINER=	bob@eager.cx
COMMENT=	Edinburgh Compatible Context Editor

LICENSE=	CC0-1.0

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ecce ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ecce.1.gz ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
