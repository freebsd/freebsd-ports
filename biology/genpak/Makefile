# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	genpak
PORTVERSION=	0.26
PORTREVISION=	9
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/genpak/download/
DISTNAME=	gp-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities to manipulate DNA sequences

LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

DEPRECATED=	Unmaintained since 2001
EXPIRATION_DATE=	2014-04-12
USES=	gmake

MAN1=	Genpak.1 gp_acc.1 gp_adjust.1 gp_cdndev.1 gp_cusage.1 gp_digest.1 \
	gp_dimer.1 gp_findorf.1 gp_gc.1 gp_getseq.1 gp_matrix.1 gp_mkmtx.1 \
	gp_pattern.1 gp_qs.1 gp_randseq.1 gp_seq2prot.1 gp_slen.1 gp_tm.1 \
	gp_trimer.1 gp_primer.1

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MDOCS}
INSTALL_TARGET=	install docs
.endif
.include <bsd.port.mk>
