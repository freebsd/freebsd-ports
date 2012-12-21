# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	fastjar
PORTVERSION=	0.93.20060808
CATEGORIES=	archivers java
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	maho/fastjar

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Version of JDK's `jar' command written entirely in C

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
PORTDOCS=	CHANGES ChangeLog NEWS README
PLIST_FILES=	bin/fastjar bin/grepjar

INFO=		fastjar
MAN1=		fastjar.1 grepjar.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
