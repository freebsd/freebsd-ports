# Created by: Tony Maher
# $FreeBSD$

PORTNAME=	mummer
PORTVERSION=	3.23
CATEGORIES=	biology
MASTER_SITES=	SF
DISTNAME=	MUMmer${PORTVERSION}

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A modular system for rapid whole genome alignment

USES=		gmake

PROGRAMS=	annotate combineMUMs delta-filter gaps \
		mgaps mummer repeat-match show-aligns \
		show-coords show-diff show-snps show-tiling
SCRIPTS=	dnadiff exact-tandems mapview mummerplot nucmer \
		nucmer2xfig promer run-mummer1 run-mummer3
DOCUMENTS=	COPYRIGHT INSTALL LICENSE README

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
.for program in ${PROGRAMS}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${program} ${PREFIX}/bin)
.endfor

.for script in ${SCRIPTS}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${script} ${PREFIX}/bin)
.endfor

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCUMENTS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
