# ex:ts=8
# New ports collection makefile for:	janosvm
# Date created:			Jun 19, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	janosvm
PORTVERSION=	0.5.1
CATEGORIES=	java
MASTER_SITES=	http://www.cs.utah.edu/flux/janos/%SUBDIR%/
MASTER_SITE_SUBDIR=	${DISTNAME}

MAINTAINER=	ijliao@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	janosvm.1 jsihey.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/janosvm
	${CP} -R ${WRKSRC}/FAQ ${PREFIX}/share/doc/janosvm
	${CP} -R ${WRKSRC}/doc ${PREFIX}/share/doc/janosvm
.endif

.include <bsd.port.mk>
