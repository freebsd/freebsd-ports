# ex:ts=8
# New ports collection makefile for:	gengetopt
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	gengetopt
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	cyrille.lefevre@laposte.net
COMMENT=	A tool for generating a C function which parses command line arguments

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		gengetopt.1

.if defined(NOPORTDOCS)
do-install:
	@cd ${INSTALL_WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install
	@cd ${INSTALL_WRKSRC}/doc && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} install-man
.endif

.include <bsd.port.mk>
