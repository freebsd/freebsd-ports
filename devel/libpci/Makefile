# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	libpci
PORTVERSION=	3.5.2
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/software/utils/pciutils \
		ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		LOCAL/sunpoet
DISTNAME=	pciutils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration space I/O made easy

LICENSE=	GPLv2

RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids

ALL_TARGET=	lib/libpci.a
CPPFLAGS+=	-fPIC
MAKE_ENV=	LANG=C
USE_LDCONFIG=	yes
USES=		gmake tar:xz

PLIST_FILES=	${LIBPCI_FILES} \
		lib/libpci.so

LIBPCI_FILES=	include/pci/config.h \
		include/pci/header.h \
		include/pci/pci.h \
		include/pci/types.h \
		lib/libpci.a \
		lib/libpci.so.3 \
		libdata/pkgconfig/libpci.pc

post-patch:
	@${LN} -s . ${WRKSRC}/lib/pci
	@${REINPLACE_CMD} -e '/^CC=/d; /^CFLAGS=/ s|=|+=|; /^IDSDIR=/ s|$$|/pciids|; /^OPT=/d; /^PREFIX=/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|^#include "|&pci/|' ${WRKSRC}/lib/pci.h

post-build:
	@cd ${WRKSRC}/lib/ && ${CC} ${CFLAGS} ${STRIP} -Wl,-soname=libpci.so.3 -shared *.o -lz -o libpci.so.3

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pci/
.for file in ${LIBPCI_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${file:T} ${STAGEDIR}${PREFIX}/${file}
.endfor
	${LN} -fs libpci.so.3 ${STAGEDIR}${PREFIX}/lib/libpci.so

.include <bsd.port.mk>
