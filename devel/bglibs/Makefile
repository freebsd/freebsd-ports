# New ports collection makefile for:	bglibs
# Date created:		03 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	bglibs
PORTVERSION=	1.009
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://untroubled.org/bglibs/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	One stop library package by Bruce Guenter

NOT_FOR_ARCHS=	alpha ia64

DOCS=		NEWS README TODO

pre-build:
	${ECHO_CMD} ${PREFIX}        > ${WRKSRC}/conf-home
	${ECHO_CMD} ${CC} ${CFLAGS}  > ${WRKSRC}/conf-cc

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
