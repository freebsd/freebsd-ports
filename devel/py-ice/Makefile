# New ports collection makefile for:	py-ice
# Date created:				2005-08-30
# Whom:					Boris B. Samorodov <bsam@ipt.ru>
#
# $FreeBSD$
#

PORTNAME=	Ice
PORTVERSION=	3.3.1
CATEGORIES=	devel python
MASTER_SITES=	http://www.zeroc.com/download/Ice/3.3/ \
		http://www.dirk.sh/dirk/Ice/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	Ice-${PORTVERSION}

MAINTAINER=	dirk.ye@gmail.com
COMMENT=	An Ice (Internet Communications Engine) language mapping for Python

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp
LIB_DEPENDS=	Ice.${LIB_VRS}:${PORTSDIR}/devel/ice

USE_GMAKE=	yes
USE_PYTHON=	yes
BUILD_WRKSRC=	${WRKSRC}/py
INSTALL_WRKSRC=	${WRKSRC}/py

LIB_VRS=	${PORTVERSION:S|.||g:C|1$||}
PLIST_SUB=	LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS}
.if defined(DEBUG)
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>
.if ${ARCH} == "ia64"
BROKEN=		does not compile on ia64
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

.if defined(NOPORTDOCS)
MAKE_ENV+=	NOPORTDOCS=yes
.endif

post-patch:
	${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/py/config/Make.rules

post-install:
	${ECHO} "Ice" > ${PYTHON_SITELIBDIR}/Ice.pth

.include <bsd.port.post.mk>
