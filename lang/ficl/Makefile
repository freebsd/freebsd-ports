# Created by: Bruce M Simpson
# $FreeBSD$

PORTNAME=	ficl
PORTVERSION=	4.1.0
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-all/${PORTNAME}${PORTVERSION:C/([[:digit:]]+\.[[:digit:]]+)\.0/\1/}

MAINTAINER=	pavelivolkov@googlemail.com
COMMENT=	Forth Inspired Command Language

LICENSE=	unknown
LICENSE_NAME=	BSD-style
LICENSE_TEXT=	Description of the license can be obtained from the following URL: http://ficl.sourceforge.net/license.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

MAKE_JOBS_UNSAFE=	YES

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	this port is not tested on anything other than i386 and amd64

USE_LDCONFIG=	YES

ALL_TARGET=	lib ${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} lib/lib${PORTNAME}.so lib/lib${PORTNAME}.so.${PORTVERSION} lib/lib${PORTNAME}.a

PORTDOCS=	*

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.a ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/lib${PORTNAME}.so.${PORTVERSION} ${PREFIX}/lib
	cd ${PREFIX}/lib && ${LN} -sf lib${PORTNAME}.so.${PORTVERSION} lib${PORTNAME}.so
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} -d -m 0755 ${DOCSDIR} ${DOCSDIR}/articles ${DOCSDIR}/graphics
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.ico ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/articles/* ${DOCSDIR}/articles
	${INSTALL_DATA} ${WRKSRC}/doc/graphics/* ${DOCSDIR}/graphics
.endif

.include <bsd.port.mk>
