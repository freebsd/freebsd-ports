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

LICENSE=	GPLv2 # (or later)

BUILD_WRKSRC=	${WRKSRC}/source
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

PORTDOCS=	fastDNAml_doc_1.2.txt fastDNAml_scripts.txt

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/fastDNAml ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/* ${PREFIX}/bin/${PORTNAME}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
