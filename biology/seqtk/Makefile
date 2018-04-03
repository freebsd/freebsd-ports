# $FreeBSD$

PORTNAME=	seqtk
DISTVERSION=	1.2-8
DISTVERSIONSUFFIX=	-gd210c57
CATEGORIES=	biology

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Tool for processing sequences in FASTA/FASTQ format

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

PLIST_FILES=	bin/seqtk

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/seqtk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
