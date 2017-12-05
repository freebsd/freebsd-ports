# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	snes9express
PORTVERSION=	1.43
PORTREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface for snes9x

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_sparc64=	does not compile on sparc64

RUN_DEPENDS=	snes9x:emulators/snes9x

USES=		gettext pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/snes.s9xskin \
		%%DATADIR%%/snsp.s9xskin

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|(gzFile\*)||' \
					-e 's|\*fptr;|fptr;|' ${WRKSRC}/rom.cc
	@${REINPLACE_CMD} -e 's|<endian\.h>|<sys/endian.h>|' \
		${WRKSRC}/s9xskin.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.s9xskin ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
