# New ports collection Makefile for: hmmer
# Date created:		June 29 1998
# Whom:			barnhart@genetics.wustl.edu
#
# $FreeBSD$
#

PORTNAME=	hmmer
PORTVERSION=	2.3.2
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.genetics.wustl.edu/pub/eddy/hmmer/${PORTVERSION}/

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Profile hidden Markov models for biological sequence analysis

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-threads --enable-lfs

DOCFILES=	00README COPYRIGHT INSTALL LICENSE NOTES Userguide.pdf
EXAMPLES=	7LES_DROME amino.null globins50.msf nucleic.pri rrm.sto \
		Artemia.fa amino.pri globins630.fa pkinase.sto RU1A_HUMAN \
		fn3.sto nucleic.null rrm.hmm
MAN1=		hmmalign.1 hmmbuild.1 hmmcalibrate.1 hmmconvert.1 hmmemit.1 \
		hmmer.1 hmmfetch.1 hmmindex.1 hmmpfam.1 hmmsearch.1

.if defined(WITH_PVM)
CONFIGURE_ENV+=		PVM_ROOT="${LOCALBASE}/lib/pvm" PVM_ARCH="FREEBSD"
CONFIGURE_ARGS+=	--with-pvm
BUILD_DEPENDS+=		pvm:${PORTSDIR}/net/pvm
.endif

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ${DOCFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif
	@ ${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	@ ${INSTALL_DATA} ${WRKSRC}/tutorial/${example} ${EXAMPLESDIR}
.endfor
.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
