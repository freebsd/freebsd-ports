# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	admesh
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://launchpadlibrarian.net/67068999/ \
		http://www.sourcefiles.org/Scientific/Numerical_Analysis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for processing STL triangulated solid meshes

LICENSE=	GPLv2+

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

PORTDOCS=	admesh.doc
PLIST_FILES=	bin/admesh

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admesh ${STAGEDIR}${PREFIX}/bin/
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ADMESH.DOC ${STAGEDIR}${DOCSDIR}/admesh.doc

.include <bsd.port.mk>
