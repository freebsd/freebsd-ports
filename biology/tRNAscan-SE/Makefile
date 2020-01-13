# Created by: chuynh@biolateral.com.au
# $FreeBSD$

PORTNAME=	tRNAscan-SE
PORTVERSION=	2.0.5
CATEGORIES=	biology
MASTER_SITES=	http://trna.ucsc.edu/software/
DISTFILES=	${DISTNAME:tl}${EXTRACT_SUFX}

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	Searching for tRNA genes in genomic sequence

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cmsearch:biology/infernal

USES=		perl5 autoreconf

WRKSRC=		${WRKDIR}/${DISTNAME:C,\.[0-9]+$,,}

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
