# New ports collection makefile for:   ml-doc
# Date created:        21 Aug 2007
# Whom:                Timothy Bourke <timbob@bigpond.com>
#
# $FreeBSD$
#

PORTNAME=	ml-doc
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://people.cs.uchicago.edu/~jhr/tools/downloads/ \
		http://www.cse.unsw.edu.au/~tbourke/distfiles/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	timbob@bigpond.com
COMMENT=	Language and tools for documenting Standard ML libraries

BUILD_DEPENDS=	smlnj-devel>=110.71:${PORTSDIR}/lang/sml-nj-devel \
		nsgmls:${PORTSDIR}/textproc/jade
RUN_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	SMLNJ_DEVEL=yes
ALL_TARGET=	build
MAKE_ENV+=	DATADIR=${DATADIR} SMLNJ_DEVEL=yes

SUB_FILES=	ml-doc.1 mkdoc.1 fix-cml-doc.sh
MAN1=		ml-doc.1 mkdoc.1
MLINKS=		ml-doc.1 extract-sig.1 ml-doc.1 extract-info.1 \
		ml-doc.1 merge-info.1 ml-doc.1 html-gen.1 \
		ml-doc.1 html-index.1 ml-doc.1 html-toc.1 \
		ml-doc.1 latex-gen.1 ml-doc.1 proof-latex.1 \
		ml-doc.1 filter-index.1 ml-doc.1 mk-mldoc-makefile.1

OPTIONS=	LATEX "Install LaTeX if necessary (needed for pdf output)" OFF

.include <bsd.port.pre.mk>

.if defined(WITH_LATEX)
RUN_DEPENDS+=	latex:${PORTSDIR}/print/teTeX
.endif

post-extract:
	@${CP} ${FILESDIR}/lib-Makefile ${WRKSRC}/lib/Makefile

post-install:
	@${INSTALL_MAN} ${WRKDIR}/ml-doc.1 ${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKDIR}/mkdoc.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
