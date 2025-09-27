PORTNAME=	makeself
DISTVERSION=	2.6.0
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/megastep/makeself/releases/download/release-${PORTVERSION}/
EXTRACT_SUFX=	.run

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Neat script to make self-extracting archives
WWW=		https://makeself.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		makeself

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/makeself \
		bin/makeself-header \
		bin/makeself-header.sh \
		bin/makeself.sh \
		share/man/man1/makeself.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
.for i in makeself makeself-header
	${INSTALL_SCRIPT} ${WRKSRC}/${i}.sh ${STAGEDIR}${PREFIX}/bin
	@${LN} -sf ${i}.sh ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
	${INSTALL_MAN} ${WRKSRC}/makeself.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
