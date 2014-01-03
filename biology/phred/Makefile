# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	phred
PORTVERSION=	0.020425.c
CATEGORIES=	biology
MASTER_SITES=	# put the tarball manually
DISTNAME=	${PORTNAME}-dist-${PORTVERSION:S/0.//}-acd
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	mzaki@biol.s.u-tokyo.ac.jp
COMMENT=	Base calling and quality value assignment on DNA sequencing

RESTRICTED=	Redistribution is not permitted in any form. You must request the tarball via e-mail. Free for academic use.
.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes

ALL_TARGET=	phred daev

BINMODE=	0111	# avoid copying binaries as required by the agreement
BINARIES=	phred daev
.for f in ${BINARIES}
PLIST_FILES+=	bin/${f}
.endfor

DATADIR=	${PREFIX}/etc/PhredPar
DATAFILES=	phredpar.dat
.for f in ${DATAFILES}
PORTDATA+=	${f}.dist
.endfor

PORTDOCS=	NEWS PHRED.DOC DAEV.DOC

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.for f in ${DISTFILES}
.if !exists(${DISTDIR}/${f})
IGNORE=	you must request the source code \(${f}\) via e-mail, place it manually in ${DISTDIR}, and then try it again
.endif
.endfor

do-install:
.for f in ${BINARIES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
	@${MKDIR} ${DATADIR}
.for f in ${DATAFILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/${f}.dist
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${ECHO} "---------------------------------------------------------------------------"
	@${ECHO} "You must set PHRED_PARAMETER_FILE environment variable."
	@${ECHO} ""
	@${ECHO} "The default parameter file in the distribution is located at:"
	@${ECHO} "  ${DATADIR}/phredpar.dat.dist"
	@${ECHO} "---------------------------------------------------------------------------"

.include <bsd.port.post.mk>
