# New ports collection makefile for:	telak
# Date created:				13 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	telak
PORTVERSION=	0.5
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://julien.danjou.info/telak/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A tool to draw pictures on your root window

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		gcrypt.16:${PORTSDIR}/security/libgcrypt

USE_GMAKE=	yes
USE_EFL=	imlib2
MAKE_JOBS_SAFE=	yes

ALL_TARGET=	${PORTNAME}
MAKE_ENV=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/telak
MAN1=		telak.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1

post-install:
	@${CAT} ${PKGMESSAGE}

install-user:
	@${SH} ${FILESDIR}/install-user

.include <bsd.port.mk>
