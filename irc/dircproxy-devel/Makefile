# New ports collection makefile for:	dircproxy
# Date created:				11 January 2001
# Whom:					George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	dircproxy
PORTVERSION=	1.2.0.b2
CATEGORIES=	irc
MASTER_SITES=	http://dircproxy.securiweb.net/pub/1.2/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/-beta/g}
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A detachable irc proxy server with many features

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		dircproxy.1 dircproxy-crypt.1
.endif

post-install:
.if !defined(NO_INSTALL_MANPAGES)
		@cd ${WRKSRC}/doc && make install-man
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
