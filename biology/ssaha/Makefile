# Created by: Fernan Aguero <fernan@iib.unsam.edu.ar>
# $FreeBSD$

PORTNAME=	ssaha
PORTVERSION=	3.1c
PORTREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.sanger.ac.uk/pub4/resources/software/ssaha/
DISTNAME=	${PORTNAME}_v${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Very fast matching and alignment of DNA sequences

NO_WRKSUBDIR=	yes
BUILD_WRKSRC=		${WRKSRC}/Binary

USES=		gmake
USE_GCC=	any
MAKE_ENV=	CCC="${CXX}" OPTIM="${CXXFLAGS}" THREAD_LIB="-pthread"
MAKEFILE=	makefile
ALL_TARGET=	ssaha

PLIST_FILES=	bin/ssaha %%DATADIR%%/testSSAHA.csh \
		${DATA_FILES:S,^,%%DATADIR%%/,}

DATA_FILES=	test.fasta test_extract.fasta test_filter.fail \
		test_filter.fastq test_protein.fasta README

do-install:
	(cd ${BUILD_WRKSRC} && ${INSTALL_PROGRAM} ssaha \
		${STAGEDIR}${PREFIX}/bin)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${BUILD_WRKSRC} && ${INSTALL_SCRIPT} testSSAHA.csh \
		${STAGEDIR}${DATADIR})
.for i in ${DATA_FILES}
	(cd ${BUILD_WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DATADIR})
.endfor

.include <bsd.port.mk>
