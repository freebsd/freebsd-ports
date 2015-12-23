# Created by: barnhart@genetics.wustl.edu
# $FreeBSD$

PORTNAME=	hmmer
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://selab.janelia.org/pub/software/hmmer3/3.0/ \
		http://selab.janelia.org/software/hmmer3/3.0/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Profile hidden Markov models for biological sequence analysis

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USES=		perl5
CONFIGURE_ARGS+=--enable-threads

DOCFILES=	COPYRIGHT INSTALL LICENSE Userguide.pdf
EXAMPLES=	7LESS_DROME Pkinase.sto fn3.sto globins4.sto minifam.h3f minifam.h3p \
		HBB_HUMAN fn3.hmm globins4.hmm globins45.fa minifam.h3i \
		Pkinase.hmm fn3.out globins4.out minifam minifam.h3m

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

# HMMER is useless without SSE and any PC in use today should support it
# Should probably also do enable-vmx on Power processors to enable
# Altivec/VMX, but I don't have a machine to test this.
.if ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "i386"
CONFIGURE_ARGS+=--enable-sse
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	(cd ${WRKSRC}/documentation/man; for i in *.man; do \
		${INSTALL_MAN} $$i ${STAGEDIR}${PREFIX}/man/man1/`echo $$i|${SED} 's/.man/.1/'`; \
	done)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCFILES:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/tutorial/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
