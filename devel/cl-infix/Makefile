# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	infix
PORTVERSION=	19960628
PORTREVISION=	3
CATEGORIES=	devel lisp
MASTER_SITES=	http://ftp.linux.org.uk/pub/lisp/cclan/ \
		ftp://ftp.ntnu.no/pub/lisp/cclan/ \
		http://thingamy.com/cclan/ \
		http://www-jcsu.jesus.cam.ac.uk/ftp/pub/cclan/
PKGNAMEPREFIX=	cl-
DISTNAME=	${PORTNAME}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A lisp macro for reading math expressions in infix form

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}
NO_BUILD=	yes
NO_CDROM=	No fees or compensation can be charged

USE_ASDF=	yes

NO_STAGE=	yes
post-extract:
	@${MV} ${WRKSRC}/infix.cl ${WRKSRC}/infix.lisp

do-install:
	@${MKDIR} ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/*.lisp ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/infix.asd ${ASDF_PATHNAME}
	@${INSTALL_DATA} ${WRKSRC}/infix.system ${ASDF_PATHNAME}
	@${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in COPYING infix.3lisp
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
