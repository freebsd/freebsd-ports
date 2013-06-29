# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tilem
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An emulator for the Z80 series of Texas Instruments calculators

LICENSE=	GPLv3

LIB_DEPENDS=	ticalcs2:${PORTSDIR}/comms/libticalcs2

INSTALLS_ICONS=	yes
USES=		desktop-file-utils shared-mime-info
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes	# parallel builds (-jX) are broken with BSD make(1)
USE_GNOME=	gtk20

.include <bsd.port.mk>
