# New ports collection makefile for:	ftpcopy
# Date created:		5 June 2000
# Whom:			Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ftpcopy
PORTVERSION=	0.2.2
CATEGORIES=	ftp
MASTER_SITES=	http://www.ohse.de/uwe/releases/

MAINTAINER=	sobomax@FreeBSD.org

do-install:
	${MKDIR} ${PREFIX}/share/ftpcopy
	cd ${WRKSRC} && \
		${INSTALL_PROGRAM} ftpcopy ftpls ${PREFIX}/bin && \
		${INSTALL_DATA} NEWS README ${PREFIX}/share/ftpcopy

.include <bsd.port.mk>
