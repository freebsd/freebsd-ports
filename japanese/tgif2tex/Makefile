# New ports collection makefile for:	tgif2tex for Japanese
# Date created:		12 Mar 1998
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

CATEGORIES=	japanese
COMMENT=	Converting texts in figure by tgif to LaTeX commands (for Japanese)

RUN_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

MASTERDIR=	${.CURDIR}/../../print/tgif2tex
PKGDIR=		${.CURDIR}
PORTSDOCDIR=	${PREFIX}/share/doc/ja-tgif2tex
DOCSRC=		Makefile \
		example.obj \
		example.tex \
		how-to-use.tex \
		sample1.obj \
		sample2.obj

.include "${MASTERDIR}/Makefile"
