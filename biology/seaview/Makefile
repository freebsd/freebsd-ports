# ex:ts=8
# New ports collection Makefile for: seaview
# Date created:         Dec 5 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	seaview
PORTVERSION=	2004.12.16
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	Multiple DNA/protein sequence alignment editor

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CAT}
EXTRACT_BEFORE_ARGS=	#
ALL_TARGET=	${PORTNAME}

CFLAGS+=	-D HAVE_DIRENT_H \
		-D DEFAULT_HELPFILE=${PREFIX}/lib/X11/seaview/seaview.help

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/seaview_align.sh ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/seaview
	@${INSTALL_DATA} ${WRKSRC}/seaview.help ${PREFIX}/lib/X11/seaview

.include <bsd.port.mk>
