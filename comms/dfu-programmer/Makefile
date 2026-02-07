PORTNAME=	dfu-programmer
DISTVERSION=	1.1.0
CATEGORIES=	comms
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	raphael.ob@protonmail.com
COMMENT=	Device Firmware Update based USB programmer for Atmel chips
WWW=		https://github.com/dfu-programmer/dfu-programmer/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
LIBS+=		-lusb

PLIST_FILES=	bin/dfu-programmer share/man/man1/dfu-programmer.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=		BASH_COMPLETIONS DOCS
OPTIONS_DEFAULT=	BASH_COMPLETIONS

BASH_COMPLETIONS_DESC=		Install bash completions

BASH_COMPLETIONS_BUILD_DEPENDS=	gsed:textproc/gsed
BASH_COMPLETIONS_VARS=		BINARY_ALIAS=sed=${LOCALBASE}/bin/gsed \
				PLIST_FILES+=etc/bash_completion.d/dfu_programmer

post-patch:
	${REINPLACE_CMD} 's|#include <libusb-1.0/libusb.h>|#include <libusb.h>|' \
		${WRKSRC}/src/dfu-device.h \
		${WRKSRC}/src/dfu.c \
		${WRKSRC}/src/dfu.h \
		${WRKSRC}/src/libdfu.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1

do-install-BASH_COMPLETIONS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/dfu_programmer ${STAGEDIR}${PREFIX}/etc/bash_completion.d

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${WRKSRC}/NEWS ${WRKSRC}/README.md \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
