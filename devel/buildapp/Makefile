# Created by: dunkyp
# $FreeBSD$

PORTNAME=	buildapp
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	devel lisp
MASTER_SITES=	http://www.xach.com/lisp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dunkyp@gmail.com
COMMENT=	A simple wrapper for creating executables with sbcl

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/LICENSE

USE_SBCL=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}
ALL_TARGET=

PLIST_FILES=	bin/buildapp
PORTDOCS=	*

post-patch:	.SILENT
	${REINPLACE_CMD} 's|sbcl|${SBCL}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR} "! -name LICENSE*")
.endif

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
