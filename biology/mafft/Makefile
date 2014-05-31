# Created by: Reed A. Cartwright <reed@cartwrig.ht>
# $FreeBSD$

PORTNAME=	mafft
PORTVERSION=	7.149
CATEGORIES=	biology
MASTER_SITES=	http://mafft.cbrc.jp/alignment/software/
DISTNAME=	${PORTNAME}-${PORTVERSION}-without-extensions-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	cartwright@asu.edu
COMMENT=	Multiple alignment program for amino acid or nucleotide sequences

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-without-extensions
BUILD_WRKSRC=	${WRKSRC}/core

USES=		gmake shebangfix

SHEBANG_FILES=	core/mafftash_premafft.tmpl

LIBEXEC_FILES=	dvtditr dndfast7 dndblast sextet5 mafft-distance pairlocalalign \
		pair2hat3s multi2hat3s pairash addsingle splittbfast \
		disttbfast tbfast mafft-profile f2cl mccaskillwrap contrafoldwrap \
		countlen seq2regtable regtable2seq score getlag dndpre \
		setcore replaceu restoreu setdirection makedirectionlist version
PERL_LIBEXEC_FILES=	mafftash_premafft.pl
SCRIPT_FILES=	mafft mafft-homologs.rb
LN_FILES=	einsi fftns fftnsi ginsi linsi mafft-einsi mafft-fftns \
		mafft-fftnsi mafft-ginsi mafft-linsi mafft-nwns mafft-nwnsi \
		mafft-qinsi mafft-xinsi nwns nwnsi
MAN1_FILES=	mafft.1 mafft-homologs.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: depends on thread-local storage
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|' \
	                  -e 's|^MANDIR = .*$$|MANDIR = $$(MANPREFIX)/man/man1|' \
	                  -e 's|^PREFIX = .*$$||' \
	                  -e 's|^CC = .*$$||' \
	                  -e 's|^CFLAGS = .*$$||' \
		${BUILD_WRKSRC}/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.for exec in ${LIBEXEC_FILES}
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/${exec} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.endfor
.for exec in ${PERL_LIBEXEC_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/binaries/${exec} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
.endfor
.for exec in ${SCRIPT_FILES}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${exec} ${STAGEDIR}${PREFIX}/bin
.endfor
.for exec in ${LN_FILES}
	${LN} -sf mafft ${STAGEDIR}${PREFIX}/bin/${exec}
.endfor
	${LN} -sf ../libexec/${PORTNAME}/mafft-distance ${STAGEDIR}${PREFIX}/bin/mafft-distance
	${LN} -sf ../libexec/${PORTNAME}/mafft-profile ${STAGEDIR}${PREFIX}/bin/mafft-profile
.for man in ${MAN1_FILES}
	${INSTALL_MAN} ${WRKSRC}/binaries/${man} ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/license ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
