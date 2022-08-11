PORTNAME=	port
PORTVERSION=	2002.10.02.1
PORTREVISION=	3
CATEGORIES=	devel lisp
MASTER_SITES=	ftp://ftp.linux.org.uk/pub/lisp/experimental/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	clocc-${PORTNAME}_2002-10-02-1

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Cross-Lisp portability package

WRKSRC=		${WRKDIR}/clocc-${PORTNAME}
NO_BUILD=	yes

USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${INSTALL_DATA} ${WRKSRC}/clocc-port.asd ${STAGEDIR}${ASDF_PATHNAME}/port.asd
	@${INSTALL_DATA} ${WRKSRC}/port.system ${STAGEDIR}${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${STAGEDIR}${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/port.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/port.html ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
