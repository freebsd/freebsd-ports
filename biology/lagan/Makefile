# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	lagan
PORTVERSION=	2.0
CATEGORIES=	biology
MASTER_SITES=	http://lagan.stanford.edu/lagan_web/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Efficient tools for large-scale multiple alignments of genomic DNA

LICENSE=	GPLv2

USES=		perl5
USE_PERL5=	run
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message
SUB_LIST=	LAGAN_DIR="${LAGAN_DIR}"

PLIST_FILES=	${EXECUTABLES:S,^,${PORTNAME}/,} \
		${SCRIPTS:S,^,${PORTNAME}/,} \
		${EXEUTILS:S,^,${PORTNAME}/utils/,} \
		${SCRIPTUTILS:S,^,${PORTNAME}/utils/,} \
		${READMES:S,^,${PORTNAME}/Readmes/,}
PLIST_DIRS=	${PORTNAME}/utils ${PORTNAME}/Readmes
PLIST_DIRSTRY=	${PORTNAME}

LAGAN_DIR=	${PREFIX}/${PORTNAME}

EXECUTABLES=	anchors chaos glocal mlagan order
SCRIPTS=	anal_gloc.pl lagan.pl rechaos.pl slagan.pl
EXEUTILS=	Glue bin2bl bin2mf cextract contigorder cstat dotplot fa2xfa \
		getbounds getcontigpos getlength getoverlap rc scorealign \
		scorecontigs seqmerge
SCRIPTUTILS=	cmerge2.pl draft.pl mextract.pl mf2bin.pl mpretty.pl \
		mproject.pl mrun.pl mrunfile.pl mrunpairs.pl mviz.pl
READMES=	README.FIRST README.chaos README.lagan README.mlagan \
		README.tools README.shuffle

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^CC/s|^|#| ; \
		 /^CFLAGS/s|^|#| ; \
		 s|$$(CC) -o|$$(CC) $$(CFLAGS) -o| ; \
		 s|$$(CPP) -o|$$(CXX) $$(CXXFLAGS) -o| ; \
		 s|$$(CLINKER) $$(OPTFLAGS)|$$(CXX) $$(LDFLAGS)|'

do-install:
	@${MKDIR} ${LAGAN_DIR}
.for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/${exe} ${LAGAN_DIR}
.endfor
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${LAGAN_DIR}
.endfor
	@${MKDIR} ${LAGAN_DIR}/utils
.for exeutil in ${EXEUTILS}
	${INSTALL_PROGRAM} ${WRKSRC}/utils/${exeutil} ${LAGAN_DIR}/utils
.endfor
.for scriptutil in ${SCRIPTUTILS}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/${scriptutil} ${LAGAN_DIR}/utils
.endfor
	@${MKDIR} ${LAGAN_DIR}/Readmes
.for readme in ${READMES}
	${INSTALL_DATA} ${WRKSRC}/Readmes/${readme} ${LAGAN_DIR}/Readmes
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
