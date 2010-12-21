# New ports collection makefile for:	clustalw
# Date created:				6 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	clustalw
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ebi.ac.uk/pub/software/clustalw2/%SUBDIR%/ \
		http://www.clustal.org/download/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A multiple alignment program for DNA or proteins

RESTRICTED=	No commercial use.

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/clustalw bin/clustalw2

post-install:
	${LN} -sf clustalw2 ${PREFIX}/bin/clustalw

.include <bsd.port.mk>
