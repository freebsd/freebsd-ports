# New ports collection makefile for:	fastjar
# Date created:		18 March 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	fastjar
PORTVERSION=	0.93.20060808
CATEGORIES=	archivers java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	maho/fastjar

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A version of JDK's `jar' command written entirely in C

USE_BZIP2=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
PORTDOCS=	CHANGES README
PLIST_FILES=	bin/fastjar bin/grepjar
SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_PERL5_BUILD=	yes

INFO=		fastjar
MAN1=		fastjar.1 grepjar.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
