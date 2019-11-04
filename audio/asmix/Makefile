# Created by: mtm@identd.net
# $FreeBSD$

PORTNAME=	asmix
PORTVERSION=	1.5
PORTREVISION=	3
CATEGORIES=	audio afterstep
MASTER_SITES=	http://tigr.net/afterstep/download/asmix/ \
		http://www.sourcefiles.org/Utilities/Console/A-B/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Volume control dock-app for the AfterStep Window Manager

LICENSE=	GPLv2

USES=		xorg
USE_XORG=	xpm x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-xpm \
		--with-xpm-includes=${LOCALBASE}/include \
		--with-xpm-library=${LOCALBASE}/lib

PLIST_FILES=	bin/asmix man/man1/asmix.1.gz

post-patch:
.for i in asmix.c configure autoconf/config.h.in
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g ; \
		 s|MACHINE_SOUNDCARD|SYS_SOUNDCARD|g' ${WRKSRC}/${i}
.endfor

post-build:
	@${LN} -sf asmix.man ${WRKSRC}/asmix.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} asmix \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} asmix.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
