# New ports collection makefile for:	io_lib
# Date created:				27 Aug, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	io_lib
PORTVERSION=	1.12.2
CATEGORIES=	biology
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	staden/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general purpose trace file(and Experiment File) reading interface

USE_AUTOTOOLS=	libtool:22:env
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=	srf_index_hash.1 srf_info.1 srf_list.1 illumina2srf.1 \
	srf2fasta.1 srf2fastq.1
MAN3=	read_scf_header.3 read_allocate.3 ExperimentFile.3 \
	write_reading.3 write_scf.3 read_deallocate.3 \
	fwrite_reading.3 read2scf.3 scf2read.3 \
	fwrite_scf.3 write_scf_header.3 read_reading.3 \
	read_scf.3 exp2read.3 fread_reading.3 \
	read2exp.3 fread_scf.3
MAN4=	Read.4

.include <bsd.port.mk>
