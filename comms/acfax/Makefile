# New ports collection makefile for:   acfax
# Date created:        20 February 2002
# Whom:                Darren <igla@batterybackups.net>
#
# $FreeBSD$
#

PORTNAME=	acfax
PORTVERSION=	0.981011
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	ftp://ftp.funet.fi/pub/ham/unix/Linux/misc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Recieve faxes using sound card and radio

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

PLIST_FILES=	bin/acfax
WRKSRC=		${WRKDIR}/${PORTNAME}

USE_IMAKE=	yes

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
	${INSTALL_PROGRAM} ${WRKSRC}/acfax ${PREFIX}/bin

.include <bsd.port.mk>
