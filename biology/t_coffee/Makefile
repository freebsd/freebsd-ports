# New ports collection makefile for:	t_coffee
# Date created:		27 June 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	t_coffee
PORTVERSION=	2.03
CATEGORIES=	biology
MASTER_SITES=	http://igs-server.cnrs-mrs.fr/~cnotred/Packages/
DISTNAME=	T-COFFEE_distribution_Version_${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A multiple DNA or protein sequence alignment package

BUILD_DEPENDS=	clustalw:${PORTSDIR}/biology/clustalw
RUN_DEPENDS=	${BUILD_DEPENDS}

BUILD_WRKSRC=	${WRKSRC}/t_coffee_source
MAKE_ENV=	MV=${MV} USER_BIN=${PREFIX}/bin \
		CLUSTALW_4_TCOFFEE=${LOCALBASE}/bin/clustalw

MAKEFILE=	makefile
SCRIPTS=	msf_aln2fasta_aln.pl blast_aln2fasta_aln.pl \
		fasta_aln2fasta_aln_unique_name.pl extract_from_pdb \
		fugue_client t_coffee_dpa t_coffee_dpa2 mocca

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/bin/t_coffee ${PREFIX}/bin
.for scriptfile in ${SCRIPTS}
	@ ${INSTALL_SCRIPT} ${WRKSRC}/bin/${scriptfile} ${PREFIX}/bin
.endfor

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${RMDIR} ${WRKSRC}/example/aln 2>/dev/null || ${TRUE}
	@ cd ${WRKSRC}/example && ${FIND} * \
	  | ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
