# Created by: ijliao
# $FreeBSD$

PORTNAME=	trio
PORTVERSION=	1.14
CATEGORIES=	devel
MASTER_SITES=	SF/c${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fully matured and stable set of printf and string functions

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${FIND} doc | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
