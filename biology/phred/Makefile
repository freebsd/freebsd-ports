# Created by: Motomichi Matsuzaki <mzaki@biol.s.u-tokyo.ac.jp>

PORTNAME=	phred
PORTVERSION=	0.020425.c
CATEGORIES=	biology
MASTER_SITES=	# put the tarball manually
DISTNAME=	${PORTNAME}-dist-${PORTVERSION:S/0.//}-acd
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	mzaki@m.u-tokyo.ac.jp
COMMENT=	Base calling and quality value assignment on DNA sequencing

# Converted from RESTRICTED
LICENSE=	PHRED
LICENSE_NAME=	phred
LICENSE_TEXT=	Redistribution is not permitted in any form. You must request the tarball via e-mail. Free for academic use.
LICENSE_PERMS=	auto-accept

SUB_FILES=	pkg-message

.if defined(PACKAGE_BUILDING)
IGNORE=		distribution files must be obtained via the authors
.endif

NO_WRKSUBDIR=	yes

ALL_TARGET=	phred daev

BINARIES=	phred daev

DATADIR=	${PREFIX}/etc/PhredPar
DATAFILES=	phredpar.dat

PORTDOCS=	NEWS PHRED.DOC DAEV.DOC

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.for f in ${DISTFILES}
.if !exists(${DISTDIR}/${f})
IGNORE=	you must request the source code \(${f}\) via e-mail, place it manually in ${DISTDIR}, and then try it again
.endif
.endfor

do-install:
.for f in ${BINARIES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/
.endfor
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${DATAFILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}/${f}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.post.mk>
