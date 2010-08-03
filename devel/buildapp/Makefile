# New ports collection makefile for:   buildapp
# Date created:        27 March 2010
# Whom:                dunkyp
#
# $FreeBSD$
#

PORTNAME=	buildapp
PORTVERSION=	1.1
CATEGORIES=	devel lisp
MASTER_SITES=	http://www.xach.com/lisp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	dunkyp@gmail.com
COMMENT=	A simple wrapped for creating executables with sbcl

BUILD_DEPENDS=	sbcl:${PORTSDIR}/lang/sbcl
RUN_DEPENDS=	${BUILD_DEPENDS}

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/doc/LICENSE-buildapp

PLIST_FILES=	bin/buildapp
PORTDOCS=	*

WRKSRC=		${WRKDIR}/${DISTNAME}-${PORTVERSION}
ALL_TARGET=

post-extract:
	@${MV} ${WRKSRC}/doc/LICENSE ${WRKSRC}/doc/LICENSE-buildapp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR} "! -name LICENSE*")
.endif

.include <bsd.port.mk>
