# Created by: tonym
# $FreeBSD$

PORTNAME=	treeviewx
PORTVERSION=	0.5.1
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	http://darwin.zoology.gla.ac.uk/~rpage/treeviewx/download/${PORTVERSION:S/.1//}/
DISTNAME=	tv-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A phylogenetic tree viewer

USE_WX=		yes
WX_COMPS=	wx contrib
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/tv

NO_STAGE=	yes
.include <bsd.port.mk>
