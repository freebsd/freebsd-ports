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
USES=		perl5
CONFIGURE_ARGS+=--enable-threads --enable-lfs

DOCFILES=	COPYRIGHT INSTALL LICENSE Userguide.pdf
EXAMPLES=	7LESS_DROME Pkinase.sto fn3.sto globins4.sto minifam.h3f minifam.h3p \
		HBB_HUMAN fn3.hmm globins4.hmm globins45.fa minifam.h3i \
		Pkinase.hmm fn3.out globins4.out minifam minifam.h3m

OPTIONS_DEFINE=	PVM DOCS EXAMPLES
PVM_DESC=	PVM support

PVM_CONFIGURE_ENV=	PVM_ROOT="${LOCALBASE}/lib/pvm" PVM_ARCH="FREEBSD"
PVM_CONFIGURE_WITH=	pvm
PVM_BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm

post-install:
	(cd ${WRKSRC}/documentation/man; for i in *.man; do \
		${INSTALL_MAN} $$i ${STAGEDIR}${PREFIX}/man/man1/`echo $$i|${SED} 's/.man/.1/'`; \
	done)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/tutorial/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
