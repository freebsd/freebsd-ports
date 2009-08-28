# ex:ts=8
# New ports collection makefile for:	MUMmer
# Date created:				20 November 2007
# Whom:					Tony Maher
#
# $FreeBSD$
#

PORTNAME=	mummer
PORTVERSION=	3.21
CATEGORIES=	biology
MASTER_SITES=	SF
DISTNAME=	MUMmer${PORTVERSION}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	A modular system for rapid whole genome alignment

USE_GMAKE=	yes

PROGRAMS=	annotate combineMUMs delta-filter gaps \
		mgaps mummer repeat-match show-aligns \
		show-coords show-diff show-snps show-tiling
SCRIPTS=	dnadiff exact-tandems mapview mummerplot nucmer \
		nucmer2xfig promer run-mummer1 run-mummer3
DOCUMENTS=	COPYRIGHT INSTALL LICENSE README

do-install:
.for program in ${PROGRAMS}
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${program} ${PREFIX}/bin)
.endfor

.for script in ${SCRIPTS}
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} ${script} ${PREFIX}/bin)
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCUMENTS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${doc} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
