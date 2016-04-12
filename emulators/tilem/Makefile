# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tilem
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emulator for the Z80 series of Texas Instruments calculators

LICENSE=	GPLv3

LIB_DEPENDS=	libticalcs2.so:comms/libticalcs2

USES=		desktop-file-utils pkgconfig shared-mime-info tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPT_CFLAGS=" "	# Inhibit -O3, our default CFLAGS are upheld
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
LIBS+=		-lm

# Unbreak parallel builds (-jX)
post-patch:
	@${REINPLACE_CMD} -E 's,cd (.+) && (\$$\(MAKE\)),\2 -C \1,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
