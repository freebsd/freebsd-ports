# Created by: Matthew Will <mwill@spingen.com>
# $FreeBSD$

PORTNAME=	cvschangelogbuilder
PORTVERSION=	2.5
CATEGORIES=	devel
MASTER_SITES=	SF/cvschangelogb/CVSChangelogBuilder/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to generate changelogs and reports from a CVS repository

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/docs/COPYING.TXT

RUN_DEPENDS=	p5-GD-Graph>=0:graphics/p5-GD-Graph

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}.pl
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/cvschangelogbuilder
PORTDOCS=	*

post-extract:
	@${FIND} ${WRKSRC} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${WRKSRC} -type f -exec ${CHMOD} 644 {} \;

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${STAGEDIR}${DOCSDIR}/images

.include <bsd.port.mk>
