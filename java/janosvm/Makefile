# ex:ts=8
# New ports collection makefile for:	janosvm
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	janosvm
PORTVERSION=	0.6.0
PORTREVISION=	2
CATEGORIES=	java
MASTER_SITES=	http://www.cs.utah.edu/flux/janos/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A virtual machine for executing Java bytecodes

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	janosvm.1 jsihey.1 jsiregister.1 jsiunregister.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		"Configure fails on alpha"
.endif

.if ${OSVERSION} >= 500113
BROKEN=         "Fails to link"
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/FAQ ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
