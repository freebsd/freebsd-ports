# New ports collection makefile for:	cdoc
# Date created:		2002-12-22
# Whom:			Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cdoc
PORTVERSION=	0.9.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.annexia.org/_file/

MAINTAINER=	sergei@FreeBSD.org
COMMENT=	Extracts documentation from C source code comments

BUILD_DEPENDS+=	make+:${PORTSDIR}/devel/makeplus

USE_PERL5_RUN=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	MAKEPLUS_HOME=${MAKEPLUS_HOME}
MAKE_ENV=	MAKEPLUS_HOME=${MAKEPLUS_HOME}
MAKEPLUS_HOME=	${LOCALBASE}/share/makeplus

DOCS=		README

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make+
	${REINPLACE_CMD}  -e 's,#!/usr/bin/perl,#!${PERL},' ${WRKSRC}/cdoc

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} make+ install
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
