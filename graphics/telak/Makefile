# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	telak
PORTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://julien.danjou.info/telak/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to draw pictures on your root window

LICENSE=	GPLv2

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libgcrypt.so:security/libgcrypt \
		libImlib2.so:graphics/imlib2

USES=		gmake

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/telak man/man1/telak.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

install-user:
	@${SH} ${FILESDIR}/install-user

.include <bsd.port.mk>
