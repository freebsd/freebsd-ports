# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jlint
PORTVERSION=	3.1.2
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java program analyzer and checker

USE_GCC=	yes

PLIST_FILES=	bin/jlint \
		bin/jlint.sh \
		bin/antic
PORTDOCS=	manual.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '1s,/bin/bash,/bin/sh,' ${WRKSRC}/jlint.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jlint ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/antic ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jlint.sh ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
