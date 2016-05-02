# Created by: sobomax
# $FreeBSD$

PORTNAME=	rrdmerge
PORTVERSION=	0.0.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://download.sippysoft.com/thirdparty/
DISTNAME=	${PORTNAME}-${GITREVISION}

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Utility to merge existing RRD data from backups into new RRD files

LICENSE=	GPLv3+

RUN_DEPENDS=	rrdtool:databases/rrdtool

USES=		python shebangfix tar:tbz2
SHEBANG_FILES=	rrdmergetree
GITREVISION=	b05d69bfac64
bash_CMD=	/bin/sh
NO_BUILD=	yes
NO_ARCH=	yes
PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}tree

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rrdmerge ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rrdmergetree ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
