# New ports collection makefile for:	clustalw
# Date created:				6 July 2000
# Whom:					dbader@eece.unm.edu
#
# $FreeBSD$
#

PORTNAME=	clustalw
PORTVERSION=	2.0.5
CATEGORIES=	biology
MASTER_SITES=	http://www.clustal.org/download/%SUBDIR%/ \
		ftp://ftp.ebi.ac.uk/pub/software/clustalw2/
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multiple alignment program for DNA or proteins

RESTRICTED=	No commercial use.

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/clustalw bin/clustalw2

post-install:
	${LN} -sf clustalw2 ${PREFIX}/bin/clustalw

.include <bsd.port.mk>
