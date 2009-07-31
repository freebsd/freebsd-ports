# ex:ts=8
# Ports collection makefile for:	treeviewx
# Date created:				04 August 2001
# Whom:					tonym
#
# $FreeBSD$
#

PORTNAME=	treeviewx
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/download/${PORTVERSION:S/.1//}/
DISTNAME=	tv-${PORTVERSION}

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	A phylogenetic tree viewer

USE_WX=		yes
WX_COMPS=	wx contrib
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tv

.include <bsd.port.mk>
