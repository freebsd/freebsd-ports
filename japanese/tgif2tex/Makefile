# New ports collection makefile for:	tgif2tex for Japanese
# Version required:	1.46
# Date created:		12 Mar 1998
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1998/12/13 03:38:16 kuriyama Exp $
#

PKGNAME=	ja-tgif2tex-1.46
CATEGORIES=	japanese print

RUN_DEPENDS=	nkf:${PORTSDIR}/japanese/nkf

MASTERDIR=	${.CURDIR}/../../print/tgif2tex
PKGDIR=		${.CURDIR}/pkg
PORTSDOCDIR=	${PREFIX}/share/doc/ja-tgif2tex
DOCSRC=		Makefile \
		how-to-use.tex \
		sample1.obj \
		sample2.obj \

.include "${MASTERDIR}/Makefile"
