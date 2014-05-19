# Created by: sobomax
# $FreeBSD$

PORTNAME=	rrdmerge
PORTVERSION=	0.0.1
#PORTREVISION=	0
CATEGORIES=	databases
MASTER_SITES=	http://download.sippysoft.com/thirdparty/
DISTNAME=	${PORTNAME}-${GITREVISION}
EXTRACT_SUFX=	.tbz2

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Utility to merge existing RRD data from backups into new RRD files

RUN_DEPENDS=	rrdtool:${PORTSDIR}/databases/rrdtool

USES=		tar:bzip2 shebangfix
SHEBANG_FILES=	rrdmergetree
GITREVISION=	b05d69bfac64
USE_PYTHON=	yes
bash_CMD=	/bin/sh
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME} bin/${PORTNAME}tree

PORTDOCS=	*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/rrdmerge ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rrdmergetree ${STAGEDIR}${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/README.rst ${STAGEDIR}${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
