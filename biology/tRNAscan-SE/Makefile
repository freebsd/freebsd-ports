# Created by: chuynh@biolateral.com.au
# $FreeBSD$

PORTNAME=	tRNAscan-SE
PORTVERSION=	2.0.3
CATEGORIES=	biology
MASTER_SITES=	http://trna.ucsc.edu/software/
DISTFILES=	${DISTNAME:tl}${EXTRACT_SUFX}

MAINTAINER=	mzaki@niid.go.jp
COMMENT=	Searching for tRNA genes in genomic sequence

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cmsearch:biology/infernal

WRKSRC=		${WRKDIR}/${DISTNAME:C,\.[0-9]+$,,}

GNU_CONFIGURE=	yes

USES=		perl5 autoreconf

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
