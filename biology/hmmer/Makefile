# Created by: barnhart@genetics.wustl.edu
# $FreeBSD$

PORTNAME=	hmmer
PORTVERSION=	3.0
CATEGORIES=	biology
MASTER_SITES=	ftp://selab.janelia.org/pub/software/hmmer3/3.0/ \
		http://selab.janelia.org/software/hmmer3/3.0/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Profile hidden Markov models for biological sequence analysis

GNU_CONFIGURE=	yes
USE_PERL5=	yes
CONFIGURE_ARGS+=--enable-threads --enable-lfs

DOCFILES=	COPYRIGHT INSTALL LICENSE Userguide.pdf
EXAMPLES=	7LESS_DROME Pkinase.sto fn3.sto globins4.sto minifam.h3f minifam.h3p \
		HBB_HUMAN fn3.hmm globins4.hmm globins45.fa minifam.h3i \
		Pkinase.hmm fn3.out globins4.out minifam minifam.h3m
#MAN1=		hmmalign.1 hmmbuild.1 hmmcalibrate.1 hmmconvert.1 hmmemit.1 \
#		hmmer.1 hmmfetch.1 hmmindex.1 hmmpfam.1 hmmsearch.1

OPTIONS_DEFINE=	PVM
PVM_DESC=	PVM support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPVM}
CONFIGURE_ENV+=		PVM_ROOT="${LOCALBASE}/lib/pvm" PVM_ARCH="FREEBSD"
CONFIGURE_ARGS+=	--with-pvm
BUILD_DEPENDS+=		pvm:${PORTSDIR}/net/pvm
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ${DOCFILES}
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@ ${MKDIR} ${EXAMPLESDIR}
.for example in ${EXAMPLES}
	@ ${INSTALL_DATA} ${WRKSRC}/tutorial/${example} ${EXAMPLESDIR}
.endfor
.endif

.if !defined(BATCH)
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
