# ex:ts=8
# New ports collection makefile for:	genpak
# Date created:			Feb 28, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	genpak
PORTVERSION=	0.25
CATEGORIES=	biology
MASTER_SITES=	http://www.bioinformatics.org/genpak/download/
DISTNAME=	gp-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		png.4:${PORTSDIR}/graphics/png

USE_GMAKE=	yes

MAN1=	Genpak.1 gp_acc.1 gp_cusage.1 gp_digest.1 gp_dimer.1 gp_findorf.1 \
	gp_gc.1 gp_getseq.1 gp_matrix.1 gp_mkmtx.1 gp_pattern.1 gp_qs.1 \
	gp_randseq.1 gp_seq2prot.1 gp_slen.1 gp_tm.1 gp_trimer.1 gp_primer.1

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install docs
.endif

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%MANPREFIX%%|${MANPREFIX}|g ; \
		s|%%DOCDIR%%|${PREFIX}/share/doc|g ; \
		s|%%CFLAGS%%|${CFLAGS}|g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
