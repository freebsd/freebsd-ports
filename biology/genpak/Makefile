# ex:ts=8
# New ports collection makefile for:	genpak
# Date created:			Feb 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	genpak
PORTVERSION=	0.26
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/genpak/download/
DISTNAME=	gp-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of small utilities to manipulate DNA sequences

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_GMAKE=	yes
MAKE_ENV=	GMAKE="${GMAKE}" MANPREFIX="${MANPREFIX}"

MAN1=	Genpak.1 gp_acc.1 gp_adjust.1 gp_cdndev.1 gp_cusage.1 gp_digest.1 \
	gp_dimer.1 gp_findorf.1 gp_gc.1 gp_getseq.1 gp_matrix.1 gp_mkmtx.1 \
	gp_pattern.1 gp_qs.1 gp_randseq.1 gp_seq2prot.1 gp_slen.1 gp_tm.1 \
	gp_trimer.1 gp_primer.1

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install docs
.endif

.include <bsd.port.mk>
