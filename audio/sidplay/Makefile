# Created by: Stefan Zehl <sec@42.org>
# $FreeBSD$

PORTNAME=	sidplay
PORTVERSION=	1.0.9
DISTVERSIONPREFIX=	base-
CATEGORIES=	audio emulators
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/ \
		http://www.sourcefiles.org/Multimedia/Module_Players/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commodore SID-chip emulator that plays SID music files

LICENSE=	GPLv2+

LIB_DEPENDS=	libsidplay.so:audio/libsidplay

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sidplay-includes=${LOCALBASE}/include \
		--with-sidplay-library=${LOCALBASE}/lib
PLIST_FILES=	bin/sid2wav bin/sidcon bin/sidplay

.include <bsd.port.mk>
