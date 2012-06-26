# New ports collection makefile for:	libpci
# Date created:				June 14, 2003
# Whom:					Samy Al Bahra <samy@kerneled.org>
#
# $FreeBSD$
#

PORTNAME=	libpci
PORTVERSION=	3.1.10
CATEGORIES=	devel
MASTER_SITES=	ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		LOCAL/sunpoet
DISTNAME=	pciutils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration space I/O made easy

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:${PORTSDIR}/misc/pciids

ALL_TARGET=	lib/libpci.a
MAKE_ENV=	LANG=C
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PLIST_DIRS=	include/pci
PLIST_FILES=	${LIBPCI_FILES} lib/libpci.so.3

LIBPCI_FILES=	include/pci/config.h include/pci/header.h include/pci/pci.h \
		include/pci/types.h lib/libpci.a lib/libpci.so \
		libdata/pkgconfig/libpci.pc

post-patch:
	@${LN} -s . ${WRKSRC}/lib/pci
	@${REINPLACE_CMD} \
		-e 's|^CC=.*$$|CC=${CC}|' \
		-e 's|^CFLAGS=|CFLAGS+=|' \
		-e 's|^IDSDIR=.*$$|IDSDIR=${PREFIX}/share/pciids|' \
		-e 's|^OPT=.*$$|OPT=-fPIC|' \
		-e 's|^PREFIX=.*$$|PREFIX=${PREFIX}|' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|^#include "|&pci/|' ${WRKSRC}/lib/pci.h

post-build:
	cd ${WRKSRC}/lib/ && ${CC} ${CFLAGS} -shared *.o -lz -o libpci.so

do-install:
	${MKDIR} ${PREFIX}/include/pci/
.for file in ${LIBPCI_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${file:T} ${PREFIX}/${file}
.endfor
	${LN} -fs libpci.so ${PREFIX}/lib/libpci.so.3

.include <bsd.port.mk>
