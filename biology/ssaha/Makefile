# New ports collection makefile for:	ssaha
# Date created:				12.Jun.2008
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	ssaha
PORTVERSION=	3.1c
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://www.sanger.ac.uk/Software/analysis/${PORTNAME:U}/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Very fast matching and alignment of DNA sequences

NO_WRKSUBDIR=	yes

USE_GMAKE=	yes
MAKEFILE=	makefile
BUILD_WRKSRC=	${WRKDIR}/Binary
ALL_TARGET=	ssaha

DATA_FILES=	test.fasta test_extract.fasta test_filter.fail \
		test_filter.fastq test_protein.fasta README

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/ssaha ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${BUILD_WRKSRC}/testSSAHA.csh ${DATADIR}/
	${INSTALL_DATA} ${DATA_FILES:S,^,${BUILD_WRKSRC}/,} ${DATADIR}/

.include <bsd.port.mk>
