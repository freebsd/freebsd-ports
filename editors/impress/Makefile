# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	impress
PORTVERSION=	1.1b9
PORTREVISION=	3
CATEGORIES=	editors tk
MASTER_SITES=	TUCOWS \
		http://www.ntlug.org/~ccox/impress/
DISTNAME=	imp${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Publishing and presentation tool

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_TK_WRAPPER=	yes

PORTDOCS=	*
PLIST_FILES=	bin/impress

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/impress.tcl ${PREFIX}/bin/impress
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/src/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

.include <bsd.port.mk>
