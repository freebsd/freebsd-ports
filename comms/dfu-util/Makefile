PORTNAME=	dfu-util
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://dfu-util.sourceforge.net/releases/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Device firmware update (DFU) USB programmer
WWW=		https://dfu-util.sourceforge.net/

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/dfu-prefix bin/dfu-suffix bin/dfu-util share/man/man1/${PORTNAME}.1.gz \
		share/man/man1/dfu-prefix.1.gz share/man/man1/dfu-suffix.1.gz

.include <bsd.port.mk>
