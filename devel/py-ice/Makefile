# New ports collection makefile for:	py-ice
# Date created:				2005-08-30
# Whom:					Boris B. Samorodov <bsam@ipt.ru>
#
# $FreeBSD$
#

PORTNAME=	Ice
PORTVERSION=	3.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.zeroc.com/download/Ice/3.0/ \
		ftp://ftp.ipt.ru/pub/download/
PKGNAMEPREFIX=	py-
DISTNAME=	IcePy-${PORTVERSION}

MAINTAINER=	bsam@ipt.ru
COMMENT=	An Ice (Internet Communications Engine) language mapping for Python

LIB_DEPENDS=	Ice.30:${PORTSDIR}/devel/ice

USE_GMAKE=	yes
USE_PYTHON=	yes

CFLAGS+=	-ftemplate-depth-128 -fPIC -DPIC -Wall -D_REENTRANT ${PTHREAD_CFLAGS}
.if defined(DEBUG)
CFLAGS+=	-g
.else
CFLAGS+=	-DNDEBUG
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		"does not compile"
.endif

.if ((${ARCH} != i386) && (${ARCH} != powerpc))
MAKE_ENV=	LP64=yes
.endif

post-patch:
	${REINPLACE_CMD} 's|%%INSTALL_PROGRAM%%|${INSTALL_PROGRAM}|g; \
		s|%%INSTALL_DATA%%|${INSTALL_DATA}|g; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/config/Make.rules

post-install:
	${ECHO} "Ice" > ${PYTHON_SITELIBDIR}/Ice.pth

.include <bsd.port.post.mk>
