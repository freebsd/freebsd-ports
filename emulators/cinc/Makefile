# Created by: verm@drunkmonk.net
# $FreeBSD$

PORTNAME=	cinc
PORTVERSION=	2.1.3
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bell Laboratories cardiac computer emulator

GNU_CONFIGURE=	yes
USES=		gmake

CFLAGS+=		-fcommon

DEPRECATED=	Unmaintained and dead upstream, does not build with -fno-common (llvm 11)
EXPIRATION_DATE=2021-04-01

PLIST_FILES=	bin/cinc \
		bin/casm

post-patch:
	@${REINPLACE_CMD} -e 's|-I-||g; s|bindir)|DESTDIR)$$(&|' \
		-e 's|/usr/bin/install|${INSTALL_PROGRAM}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
