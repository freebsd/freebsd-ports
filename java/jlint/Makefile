# Created by: Ernst de Haan <znerd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jlint
PORTVERSION=	3.1.2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java program analyzer and checker

PLIST_FILES=	bin/jlint \
		bin/jlint.sh \
		bin/antic

.if !defined(NOPORTDOCS)
PORTDOCS=	manual.pdf
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '1s,/bin/bash,/bin/sh,' ${WRKSRC}/jlint.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jlint ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/antic ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/jlint.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
