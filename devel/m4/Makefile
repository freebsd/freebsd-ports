# New ports collection makefile for:	m4
# Date created:		25 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	m4
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	m4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU m4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g

.if defined(WITH_CHANGEWORD)
CONFIGURE_ARGS+=	--enable-changeword
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/examples/gm4
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/share/examples/gm4
	@install-info ${PREFIX}/info/m4.info ${PREFIX}/info/dir

.include <bsd.port.mk>
