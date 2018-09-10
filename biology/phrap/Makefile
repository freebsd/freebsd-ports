# $FreeBSD$

PORTNAME=	phrap
PORTVERSION=	1.090518
CATEGORIES=	biology
MASTER_SITES=	# put the tarball manually
DISTFILES=	distrib.tar.gz
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Phrap is a program for assembling shotgun DNA sequence data

RESTRICTED=	Redistribution is not permitted in any form. You must request the tarball via e-mail. Free for academic use.
.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes

MAKEFILE=	makefile
ALL_TARGET=	all

BINARIES=	calf_merge pcluster cross_match loco phrap swat
SCRIPTS=	phrapview

PORTDATA=	BLOSUM50 BLOSUM62 PAM250 mat50 mat70 mb_matrix penalty2 vector.seq
PORTDOCS=	general.doc phrap.doc swat.doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.for f in ${DISTFILES}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${f})
IGNORE=	you must request the source code \(${DISTFILES}\) via e-mail, place it manually in ${DISTDIR}/${DIST_SUBDIR}, and then try it again
.endif
.endfor

do-install:
.for f in ${BINARIES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for f in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${PORTDATA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
