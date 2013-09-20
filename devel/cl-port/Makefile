# Created by: Henrik Motakef <henrik.motakef@web.de>
# $FreeBSD$

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

NO_STAGE=	yes
do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/clocc-port.asd ${ASDF_PATHNAME}/port.asd
	@${INSTALL_DATA} ${WRKSRC}/port.system ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/port.html ${DOCSDIR}
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
