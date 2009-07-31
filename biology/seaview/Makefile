# ex:ts=8
# New ports collection Makefile for: seaview
# Date created:         Dec 5 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	seaview
PORTVERSION=	2006.02.13
PORTREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/archive/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tar

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Multiple DNA/protein sequence alignment editor

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk \
		pdf.8:${PORTSDIR}/print/pdflib

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=	#
ALL_TARGET=	${PORTNAME}

CFLAGS+=	-D HAVE_DIRENT_H \
		-D DEFAULT_HELPFILE=${PREFIX}/lib/X11/${PORTNAME}/seaview.help

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/seaview_align.sh ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/seaview.help ${PREFIX}/lib/X11/${PORTNAME}

.include <bsd.port.mk>
