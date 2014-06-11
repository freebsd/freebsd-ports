# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	fcplay
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Future Composer Reference Player

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/sidplay/compconf.h:${PORTSDIR}/audio/libsidplay

USES=		gmake
GNU_CONFIGURE=	yes
CXXFLAGS+=	-I${LOCALBASE}/include
PORTDOCS=	ABOUT POINTER
PLIST_FILES=	bin/fcplay

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
.for f in configure Config.h.in
	@${REINPLACE_CMD} -e "s@machine/soundcard\.h@sys/soundcard\.h@g; \
		s@HAVE_MACHINE_SOUNDCARD_H@HAVE_SYS_SOUNDCARD_H@g" \
		${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fcplay ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
