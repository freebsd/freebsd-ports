PORTNAME=	libcddb-doc
PORTVERSION=	1.3.0
CATEGORIES=	audio
MASTER_SITES=	SF/libcddb/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Libcddb documentation

USES=		tar:bzip2
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/output

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
