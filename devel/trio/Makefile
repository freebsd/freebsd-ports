# Created by: ijliao
# $FreeBSD$

PORTNAME=	trio
PORTVERSION=	1.14
CATEGORIES=	devel
MASTER_SITES=	SF/c${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A fully matured and stable set of printf and string functions

GNU_CONFIGURE=	yes

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} doc | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
