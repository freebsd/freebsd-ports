# Created by: Motomichi Matsuzaki <mzaki@e-mail.ne.jp>
# $FreeBSD$

PORTNAME=	fastdnaml
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://www.life.illinois.edu/gary/programs/fastDNAml/
DISTNAME=	fastDNAml_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Faster DNAML, makes phylogenetic trees using maximum likelihood

LICENSE=	GPLv2+

BUILD_WRKSRC=	${WRKSRC}/source
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PORTDOCS=	fastDNAml_doc_1.2.txt fastDNAml_scripts.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/fastDNAml ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
