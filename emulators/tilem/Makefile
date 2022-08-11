PORTNAME=	tilem
PORTVERSION=	2.0
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Texas Instruments Z80 series calculator emulator

LICENSE=	GPLv3

LIB_DEPENDS=	libticalcs2.so:comms/libticalcs2

USES=		desktop-file-utils gnome pkgconfig shared-mime-info tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPT_CFLAGS=" "	# Inhibit -O3, our default CFLAGS are upheld
USE_GNOME=	gtk20
LIBS+=		-lm
PORTDOCS=	CHANGELOG KEYS NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

# Unbreak parallel builds (-jX)
post-patch:
	@${REINPLACE_CMD} -E 's,cd (.+) && (\$$\(MAKE\)),\2 -C \1,' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
