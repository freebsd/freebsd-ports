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

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/docs/*.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/images/* ${STAGEDIR}${DOCSDIR}/images

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1100077
# chmod -R bug.
post-extract:
	@${CHMOD} 755 ${WRKSRC}/docs/images
.endif

.include <bsd.port.post.mk>
