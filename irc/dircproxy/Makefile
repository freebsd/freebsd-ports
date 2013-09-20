# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	dircproxy
DISTVERSION=	1.2.0-RC1
CATEGORIES=	irc
MASTER_SITES=	http://dircproxy.googlecode.com/files/
PKGNAMESUFFIX=	-devel

MAINTAINER=	mm@FreeBSD.org
COMMENT=	A detachable irc proxy server with many features

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.if !defined(NO_INSTALL_MANPAGES)
MAN1=		dircproxy.1 dircproxy-crypt.1
.endif

NO_STAGE=	yes
post-install:
.if !defined(NO_INSTALL_MANPAGES)
		@cd ${WRKSRC}/doc && make install-man
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
