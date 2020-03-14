# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	hexter
PORTVERSION=	1.0.3
CATEGORIES=	audio
MASTER_SITES=	SF/dssi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSSI softsynth that models the sound generation of a Yamaha DX7

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libdssialsacompat.so:audio/libdssialsacompat \
		liblo.so:audio/liblo \
		libjack.so:audio/jack
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:audio/dssi

USES=		gmake gnome libtool pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/dssi/hexter.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
