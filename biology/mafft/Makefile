# ex:ts=8
# New ports collection makefile for:	mafft
# Date created:				1 Feb 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	mafft
PORTVERSION=	6.903
CATEGORIES=	biology
MASTER_SITES=	http://mafft.cbrc.jp/alignment/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}-without-extensions-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	cartwright@asu.edu
COMMENT=	Multiple alignment program for amino acid or nucleotide sequences

LICENSE=	BSD

RUN_DEPENDS=	lav2ps:${PORTSDIR}/biology/fasta3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-without-extensions
BUILD_WRKSRC=	${WRKSRC}/core

USE_GMAKE=	yes

MAN1=		mafft.1 mafft-homologs.1

LIBEXEC_FILES=	dvtditr dndfast7 dndblast sextet5 mafft-distance pairlocalalign \
		pair2hat3s multi2hat3s rnatest pairash addsingle splittbfast \
		disttbfast tbfast mafft-profile f2cl mccaskillwrap contrafoldwrap \
		countlen seq2regtable regtable2seq score getlag dndpre dndpre2 \
		setcore replaceu restoreu setdirection makedirectionlist version
SCRIPT_FILES=	mafft mafft-homologs.rb
LN_FILES=	einsi fftns fftnsi ginsi linsi mafft-einsi mafft-fftns \
		mafft-fftnsi mafft-ginsi mafft-linsi mafft-nwns mafft-nwnsi \
		mafft-qinsi mafft-xinsi nwns nwnsi

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
	                  -e 's|^MANDIR = .*$$|MANDIR = $$(MANPREFIX)/man/man1|' \
	                  -e 's|^PREFIX = .*$$||' \
	                  -e 's|^CC = .*$$||' \
	                  -e 's|^CFLAGS = .*$$||' \
		${BUILD_WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/libexec/${PORTNAME}
.for exec in ${LIBEXEC_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/${exec} ${PREFIX}/libexec/${PORTNAME}
.endfor
.for exec in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${exec} ${PREFIX}/bin
.endfor
.for exec in ${LN_FILES}
	${LN} -fs ${PREFIX}/bin/mafft ${PREFIX}/bin/${exec}
.endfor
	${LN} -fs ${PREFIX}/libexec/${PORTNAME}/mafft-distance ${PREFIX}/bin/mafft-distance
	${LN} -fs ${PREFIX}/libexec/${PORTNAME}/mafft-profile ${PREFIX}/bin/mafft-profile
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/binaries/${man} ${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
