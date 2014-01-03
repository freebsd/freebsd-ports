# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	phd2fasta
PORTVERSION=	0.990622.f
CATEGORIES=	biology
MASTER_SITES=	# put the tarball manually
DISTFILES=	phd2fasta-acd-dist.tar.Z

MAINTAINER=	mzaki@biol.s.u-tokyo.ac.jp
COMMENT=	A converter from output files of Phred/Consed to FASTA files

RESTRICTED=	Redistribution is not permitted in any form. You must request the tarball via e-mail. Free for academic use.
.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes

ALL_TARGET=	phd2fasta

BINMODE=	0111	# avoid copying binaries as required by the agreement
BINARIES=	phd2fasta
PLIST_FILES=	bin/phd2fasta

PORTDOCS=	PHD2FASTA.DOC

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.for f in ${DISTFILES}
.if !exists(${DISTDIR}/${f})
IGNORE=	you must request the source code (${f}) via e-mail, place it manually in ${DISTDIR}, and then try it again
.endif
.endfor

do-install:
.for f in ${BINARIES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
