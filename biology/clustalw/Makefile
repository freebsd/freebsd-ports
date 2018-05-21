# Created by: dbader@eece.unm.edu
# $FreeBSD$

PORTNAME=	clustalw
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ebi.ac.uk/pub/software/clustalw2/${PORTVERSION}/ \
		http://www.clustal.org/download/${PORTVERSION}/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Multiple alignment program for DNA or proteins

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/clustalw bin/clustalw2

post-install:
	${LN} -sf clustalw2 ${STAGEDIR}${PREFIX}/bin/clustalw

.include <bsd.port.mk>
