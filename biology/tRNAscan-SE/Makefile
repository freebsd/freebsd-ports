PORTNAME=	tRNAscan-SE
PORTVERSION=	2.0.11
CATEGORIES=	biology
MASTER_SITES=	http://trna.ucsc.edu/software/
DISTFILES=	${DISTNAME:tl}${EXTRACT_SUFX}

MAINTAINER=	mzaki@e-mail.ne.jp
COMMENT=	Searching for tRNA genes in genomic sequence
WWW=		http://lowelab.ucsc.edu/tRNAscan-SE/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	cmsearch:biology/infernal

USES=		autoreconf perl5

GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:C,\.[0-9]+$,,}

.include <bsd.port.mk>
