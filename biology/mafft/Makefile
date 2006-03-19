# ex:ts=8
# New ports collection makefile for:	mafft
# Date created:				1 Feb 2006
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	mafft
PORTVERSION=	5.743
CATEGORIES=	biology
MASTER_SITES=	http://www.biophys.kyoto-u.ac.jp/~katoh/programs/align/mafft/ \
		http://genoma.unsam.edu.ar/~fernan/freebsd/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Multiple sequence alignments based on fast Fourier transform

RUN_DEPENDS=	fasta34:${PORTSDIR}/biology/fasta3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/src

MAKE_ENV+=	CFLAG="${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|PREFIX) =,\1 ?=,' \
		${WRKSRC}/src/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/mafft ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/* ${PREFIX}/bin
	@ ${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/* ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme ${DOCSDIR}
.endif

.include <bsd.port.mk>
