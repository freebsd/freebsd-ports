# New Ports collection makefile for:	xvmixer
# Date created:			Tue Apr 15 23:07:07 EDT 2003
# Whom:				Serge Gagnon <gagnon__s@videotron.ca>
#
# $FreeBSD$
#

PORTNAME=	xvmixer
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	http://ftp.auxio.org/pub/mirrors/step.polymtl.ca/pub/Xview/apps/xvmixer/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open Look-based audio mixer

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

PLIST_FILES=	bin/xvmixer
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvmixer ${LOCALBASE}/bin

.include <bsd.port.mk>
