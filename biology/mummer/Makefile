# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	mummer
PORTVERSION=	3.23
CATEGORIES=	biology
MASTER_SITES=	SF
DISTNAME=	MUMmer${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular system for rapid whole genome alignment

USES=		gmake

PROGRAMS=	annotate combineMUMs delta-filter gaps \
		mgaps mummer repeat-match show-aligns \
		show-coords show-diff show-snps show-tiling
SCRIPTS=	dnadiff exact-tandems mapview mummerplot nucmer \
		nucmer2xfig promer run-mummer1 run-mummer3
DOCUMENTS=	COPYRIGHT INSTALL LICENSE README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCUMENTS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
