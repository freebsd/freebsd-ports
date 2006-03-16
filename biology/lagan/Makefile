# New ports collection makefile for:	lagan
# Date created:		07 Dec 2005
# Whom:	      		Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	lagan
PORTVERSION=	1.2
CATEGORIES=	biology
MASTER_SITES=	http://lagan.stanford.edu/lagan_web/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Efficient tools for large-scale multiple alignments of genomic DNA

LAGAN_DIR=	${PREFIX}/${PORTNAME}
USE_PERL5_RUN=	yes
SUB_FILES=	pkg-message
SUB_LIST=	LAGAN_DIR=${LAGAN_DIR}

EXECUTABLES=	anchors chaos glocal mlagan order
SCRIPTS=	anal_gloc.pl lagan.pl rechaos.pl slagan.pl
EXEUTILS=	Glue bin2bl bin2mf cextract contigorder cstat dotplot fa2xfa \
		getbounds getcontigpos getlength getoverlap rc scorealign \
		scorecontigs seqmerge
SCRIPTUTILS=	cmerge2.pl draft.pl mextract.pl mf2bin.pl mpretty.pl \
		mproject.pl mrun.pl mrunfile.pl mrunpairs.pl mviz.pl

MAKE_ENV+=	CC="${CC} ${CFLAGS}" CPP="${CXX} ${CXXFLAGS}"

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CPP) =,\1 ?=,g' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${LAGAN_DIR}
	${CP} -R ${WRKSRC}/Readmes ${LAGAN_DIR}
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
