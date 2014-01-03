# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	phrap
PORTVERSION=	0.990329
CATEGORIES=	biology
MASTER_SITES=	# put the tarball manually
DISTFILES=	distrib.tar.Z
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mzaki@biol.s.u-tokyo.ac.jp
COMMENT=	Phrap is a program for assembling shotgun DNA sequence data

RESTRICTED=	Redistribution is not permitted in any form. You must request the tarball via e-mail. Free for academic use.
.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes

MAKEFILE=	makefile
ALL_TARGET=	all manyreads

BINARIES=	cluster cross_match cross_match.manyreads loco \
		phrap phrap.longreads phrap.manyreads swat
SCRIPTS=	phrapview
.for f in ${BINARIES} ${SCRIPTS}
PLIST_FILES+=	bin/${f}
.endfor

PORTDATA=	BLOSUM50 BLOSUM62 PAM250 mat50 mat70 penalty2 vector.seq
PORTDOCS=	general.doc phrap.doc swat.doc

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.for f in ${DISTFILES}
.if !exists(${DISTDIR}/${DIST_SUBDIR}/${f})
IGNORE=	you must request the source code \(${DISTFILES}\) via e-mail, place it manually in ${DISTDIR}/${DIST_SUBDIR}, and then try it again
.endif
.endfor

do-install:
.for f in ${BINARIES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
	@${CHMOD} a-r ${PREFIX}/bin/${f} # as required by the agreement
.endfor
.for f in ${SCRIPTS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
	@${MKDIR} ${DATADIR}
.for f in ${PORTDATA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
