# New ports collection makefile for:	dna-qc
# Date created:				25 Novemeber 2001
# Whom:					Tony Maher <tonym@biolateral.com.au>
#
# $FreeBSD$
#

PORTNAME=	dna-qc
PORTVERSION=	1993.07.26
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.tigr.org/pub/software/qc/
DISTNAME=	qc
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tonym@biolateral.com.au
COMMENT=	A quality control algorithm for DNA sequencing projects

NO_WRKSUBDIR=	true
USE_REINPLACE=	yes

EXAMPLES=	README script.compare script.limits \
		bact.all chromosomeIII.all human.all worm.all
PROGRAMS=	counter hybridize normalize random_clip random_line

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} >= 502102
BROKEN=		"Does not compile"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^CFLAGS,#CFLAGS,' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' ${WRKSRC}/normalize.c
	@${REINPLACE_CMD} -e 's,fname\*,fname,' ${WRKSRC}/random_line.c
	@${REINPLACE_CMD} -e 's,static void allocate_pool,void allocate_pool,' \
		${WRKSRC}/stringpool.c

do-install:
.for file in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
	${STRIP_CMD} ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/qc_doc/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/surprize_doc/* ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
