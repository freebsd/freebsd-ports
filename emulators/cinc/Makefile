# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	cinc
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bell Laboratories cardiac computer emulator

GNU_CONFIGURE=	yes
USES=		gmake

CFLAGS+=		-fcommon

EXPIRATION_DATE=	2020-09-30
DEPRECATED=		Unmaintained and dead upstream

PLIST_FILES=	bin/cinc \
		bin/casm

post-patch:
	@${REINPLACE_CMD} -e 's|-I-||g; s|bindir)|DESTDIR)$$(&|' \
		-e 's|/usr/bin/install|${INSTALL_PROGRAM}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
