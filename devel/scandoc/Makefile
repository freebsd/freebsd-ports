# Created by: Christopher Elkins <chrise@scardini.com>
# $FreeBSD$

PORTNAME=	scandoc
PORTVERSION=	0.14
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C/C++ documentation generator

LICENSE=	ARTPERL10
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "images templates test" \
			${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README scandoc.html \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
