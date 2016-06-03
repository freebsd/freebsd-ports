# Created by: Matthew X. Economou <xenophon+fbsdports@irtnog.org>
# $FreeBSD$

PORTNAME=	uffi
PORTVERSION=	2.1.2
CATEGORIES=	devel lisp
PKGNAMEPREFIX=	cl-
MASTER_SITES=	http://files.b9.com/uffi/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Universal Foreign Function Interface for Common Lisp

BROKEN=		Does not fetch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04
NO_BUILD=	yes

USE_ASDF=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/src
	${INSTALL_DATA} ${WRKSRC}/uffi.asd   ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/src/*.lisp ${STAGEDIR}${ASDF_PATHNAME}/src
	${LN} -sf ${ASDF_PATHNAME}/uffi.asd ${STAGEDIR}${ASDF_REGISTRY}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${STAGEDIR}${DOCSDIR} -xf ${WRKSRC}/doc/html.tar.gz --no-same-owner
	${CHMOD} ${DOCMODE}  ${STAGEDIR}${DOCSDIR}/html/*
	${INSTALL_DATA} ${WRKSRC}/doc/uffi.pdf ${STAGEDIR}${DOCSDIR}
.for FILE in AUTHORS ChangeLog INSTALL LICENSE NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
