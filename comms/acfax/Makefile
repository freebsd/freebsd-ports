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

LICENSE=	GPLv2

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

USES=		imake xorg

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xext xmu xt sm ice

PLIST_FILES=	bin/acfax

post-extract:
	@${TOUCH} ${WRKSRC}/acfax.man

post-patch:
	@${REINPLACE_CMD} -e 's|regex.h|gnuregex.h|' ${WRKSRC}/RegExp.h
	@${REINPLACE_CMD} -e 's| -O2 -Wall||g ; \
		 s|-lm|-lm -lgnuregex|' ${WRKSRC}/Imakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acfax ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
