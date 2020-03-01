# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	libpci
PORTVERSION=	3.6.4
CATEGORIES=	devel
MASTER_SITES=	KERNEL_ORG/software/utils/pciutils \
		ftp://atrey.karlin.mff.cuni.cz/pub/linux/pci/ \
		LOCAL/sunpoet
DISTNAME=	pciutils-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PCI configuration space I/O made easy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/share/pciids/pci.ids:misc/pciids

USES=		gmake tar:xz

ALL_TARGET=	lib/libpci.a
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

PLIST_FILES=	${LIBPCI_FILES} \
		lib/libpci.so
PORTDATA=	config.mk

LIBPCI_FILES=	include/pci/config.h \
		include/pci/header.h \
		include/pci/pci.h \
		include/pci/types.h \
		lib/libpci.a \
		lib/libpci.so.3 \
		libdata/pkgconfig/libpci.pc

post-patch:
	@${LN} -s . ${WRKSRC}/lib/pci

do-configure:
	@cd ${WRKSRC}/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} lib/config.h

post-build:
	@cd ${WRKSRC}/lib/ && ${CC} ${CFLAGS} ${STRIP} -Wl,-soname=libpci.so.3 -shared *.o -lz -o libpci.so.3

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/pci/ ${STAGEDIR}${DATADIR}/
.for file in ${LIBPCI_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${file:T} ${STAGEDIR}${PREFIX}/${file}
.endfor
	${LN} -fs libpci.so.3 ${STAGEDIR}${PREFIX}/lib/libpci.so
	${INSTALL_DATA} ${WRKSRC}/lib/config.mk ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
