# New ports collection makefile for:	xmcd
# Version required:	2.4
# Date created:		16 Februar 1995
# Whom:			Gennady Sorokopud <gena@NetVision.net.il>
#
# $FreeBSD$
#

DISTNAME=	xmcd-2.6
CATEGORIES=	audio
MASTER_SITES=	http://metalab.unc.edu/tkan/download/xmcd/src/

MAINTAINER=	eischen@vigrid.com

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
PLIST_SUB+=	RELEASE=${OSREL:R} ARCH=${ARCH}

MAN1=		cda.1 cddbcmd.1 dp2xmcd.1 wm2xmcd.1 xmcd.1
MANCOMPRESSED=	no

post-extract:
	@${CHMOD} -R u+w ${WRKSRC}

pre-patch:
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${WRKSRC}/xmcd_d/XMcd.ad.in

post-patch:
	@${SED} -e "s;@PREFIX@;${PREFIX};g" ${WRKSRC}/xmcd_d/XMcd.ad.in \
		> ${WRKSRC}/xmcd_d/XMcd.ad

post-install:
	@${CAT} ${PKGMESSAGE}
	@${CP} ${WRKSRC}/xmcd_d/XMcd.ad ${PREFIX}/lib/X11/app-defaults/XMcd

.include <bsd.port.mk>
