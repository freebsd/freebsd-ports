# Ports collection Makefile for:	PyKQueue
# Date created:				05/23/2000
# Whom:					dwhite@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		kqueue
PORTVERSION=		1.1
CATEGORIES=		devel python
MASTER_SITES=		{$MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dwhite
PKGNAMEPREFIX=		py-
DISTNAME=		PyKQueue-${PORTVERSION}

MAINTAINER=		dwhite@FreeBSD.org

BUILD_DEPENDS=		python:${PORTSDIR}/lang/python
RUN_DEPENDS=		python:${PORTSDIR}/lang/python

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 400018 || ${OSVERSION} == 500000 )
FORBIDDEN= requires kqueue
.endif

# NO_WRKSUBDIR=		yes
# MAKEFILE=		makefile

do-configure:
	@(cd ${WRKSRC} && \
	make -f Makefile.pre.in boot)

do-install:
	${MKDIR} ${PREFIX}/lib/python1.5/site-packages
	${INSTALL_DATA} ${WRKSRC}/kqsyscallmodule.so                   \
		${PREFIX}/lib/python1.5/site-packages/
	${INSTALL_DATA} ${WRKSRC}/KQueue.py				\
		${PREFIX}/lib/python1.5/site-packages/
# .if !defined(NOPORTDOCS)
# 	${INSTALL_DATA} ${WRKSRC}/kjbuckets.html ${PREFIX}/share/doc/
# .endif

.include <bsd.port.post.mk>
