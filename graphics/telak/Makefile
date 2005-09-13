# New ports collection makefile for:	telak
# Date created:				13 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	telak
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=	http://critical.ch/distfiles/

MAINTAINER=	ehaupt@critical.ch
COMMENT=	A tool to draw pictures on your root window

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl \
		gcrypt.13:${PORTSDIR}/security/libgcrypt \
		Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GETOPT_LONG=yes

ALL_TARGET=	${PORTNAME}
MAKE_ENV=	CC="${CC}" CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

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
