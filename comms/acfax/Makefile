# New ports collection makefile for:   acfax
# Date created:        20 February 2002
# Whom:                Darren <igla@batterybackups.net>
#
# $FreeBSD$
#

PORTNAME=	acfax
PORTVERSION=	0.981011
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.funet.fi/pub/ham/unix/Linux/misc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0.//}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Recieve faxes using sound card and radio

BUILD_DEPENDS=	${X11BASE}/lib/libXaw3d.a:${PORTSDIR}/x11-toolkits/Xaw3d
RUN_DEPENDS=	${X11BASE}/lib/libXaw3d.a:${PORTSDIR}/x11-toolkits/Xaw3d

WRKSRC=		${WRKDIR}/acfax
USE_IMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setup_fax(120, 288|setup_fax(120, 576|' \
		${WRKSRC}/acfax.c
	@${REINPLACE_CMD} -e 's|ixoc = 288|ixoc = 576|' ${WRKSRC}/fax_funcs.c
	@${REINPLACE_CMD} -e 's|regex.h|gnuregex.h|' ${WRKSRC}/RegExp.h
	@${REINPLACE_CMD} -e 's|-lm|-lm -lgnuregex|' ${WRKSRC}/Imakefile

post-configure:
		${TOUCH} ${WRKSRC}/acfax.man

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/acfax ${X11BASE}/bin

.include <bsd.port.mk>
