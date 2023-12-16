PORTNAME=	impress
PORTVERSION=	1.1b9
PORTREVISION=	3
CATEGORIES=	editors tk
MASTER_SITES=	http://www.ntlug.org/~ccox/impress/
DISTNAME=	imp${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Publishing and presentation tool
WWW=		https://www.ntlug.org/~ccox/impress/

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

DEPRECATED=	Upstream last release was in 2000
EXPIRATION_DATE=	2024-01-16

USES+=		tk

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/impress
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|exec wish|exec ${WISH}|g' \
	    ${WRKSRC}/src/impress.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/impress.tcl ${STAGEDIR}${PREFIX}/bin/impress

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/src/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
