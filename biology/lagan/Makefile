# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	lagan
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://lagan.stanford.edu/lagan_web/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Efficient tools for large-scale multiple alignments of genomic DNA

LICENSE=	GPLv2

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	slagan.pl
MAKE_JOBS_UNSAFE=yes

SUB_FILES=	pkg-message
SUB_LIST=	LAGAN_DIR="${LAGAN_DIR}"

PLIST_FILES=	${EXECUTABLES:S,^,${PORTNAME}/,} \
		${SCRIPTS:S,^,${PORTNAME}/,} \
		${EXEUTILS:S,^,${PORTNAME}/utils/,} \
		${SCRIPTUTILS:S,^,${PORTNAME}/utils/,} \
		${READMES:S,^,${PORTNAME}/Readmes/,}

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

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^CC/s|^|#| ; \
		 /^CFLAGS/s|^|#| ; \
		 s|$$(CC) -o|$$(CC) $$(CFLAGS) -o| ; \
		 s|$$(CPP) -o|$$(CXX) $$(CXXFLAGS) -o| ; \
		 s|$$(CLINKER) $$(OPTFLAGS)|$$(CXX) $$(LDFLAGS)|'
	@${FIND} ${WRKSRC}/src -name "*.c" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^inline |static inline |'

do-install:
	@${MKDIR} ${STAGEDIR}${LAGAN_DIR}
.for exe in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/${exe} ${STAGEDIR}${LAGAN_DIR}
.endfor
.for script in ${SCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${script} ${STAGEDIR}${LAGAN_DIR}
.endfor
	@${MKDIR} ${STAGEDIR}${LAGAN_DIR}/utils
.for exeutil in ${EXEUTILS}
	${INSTALL_PROGRAM} ${WRKSRC}/utils/${exeutil} ${STAGEDIR}${LAGAN_DIR}/utils
.endfor
.for scriptutil in ${SCRIPTUTILS}
	${INSTALL_SCRIPT} ${WRKSRC}/utils/${scriptutil} ${STAGEDIR}${LAGAN_DIR}/utils
.endfor
	@${MKDIR} ${STAGEDIR}${LAGAN_DIR}/Readmes
.for readme in ${READMES}
	${INSTALL_DATA} ${WRKSRC}/Readmes/${readme} ${STAGEDIR}${LAGAN_DIR}/Readmes
.endfor

.include <bsd.port.mk>
