# New ports collection makefile for:	bglibs
# Date created:		03 Mar 2003
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	bglibs
PORTVERSION=	1.019
CATEGORIES=	devel
MASTER_SITES=	http://untroubled.org/${PORTNAME}/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	One stop library package by Bruce Guenter

NOT_FOR_ARCHS=	alpha

LDFLAGS?=	-s

DOCS=		NEWS README TODO doc/html/*

do-configure:
	${ECHO_CMD} "${PREFIX}"		> ${WRKSRC}/conf-home
	${ECHO_CMD} "${CC} ${CFLAGS}"	> ${WRKSRC}/conf-cc
	${ECHO_CMD} "${CC} ${LDFLAGS}"	> ${WRKSRC}/conf-ld

do-install:
	cd ${WRKSRC} && ./installer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
