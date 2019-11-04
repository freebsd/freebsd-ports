# Created by: Darren <igla@batterybackups.net>
# $FreeBSD$

PORTNAME=	acfax
PORTVERSION=	0.981011
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	ftp://ftp.funet.fi/pub/ham/unix/Linux/misc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0.//}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Receive faxes using sound card and radio

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

PLIST_FILES=	bin/acfax
WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		imake xorg
USE_XORG=	x11 xext xmu xt sm ice

post-extract:
	@${TOUCH} ${WRKSRC}/acfax.man

post-patch:
	@${REINPLACE_CMD} -e 's|setup_fax(120, 288|setup_fax(120, 576|' \
		${WRKSRC}/acfax.c
	@${REINPLACE_CMD} -e 's|ixoc = 288|ixoc = 576|' ${WRKSRC}/fax_funcs.c
	@${REINPLACE_CMD} -e 's|regex.h|gnuregex.h|' ${WRKSRC}/RegExp.h
	@${REINPLACE_CMD} -e 's| -O2 -Wall||g ; \
		 s|-lm|-lm -lgnuregex|' ${WRKSRC}/Imakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acfax ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
