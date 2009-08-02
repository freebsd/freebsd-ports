# New ports collection makefile for:	klipoquery
# Date created:				Wed Jun 29 12:30:12 CEST 2005
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	klipoquery
PORTVERSION=	0.2.4
PORTREVISION=	5
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.michael-vonrueden.de/${PORTNAME}/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Panel applet for web searches using clipboard entries

EXTRA_PATCHES=	${.CURDIR}/../../x11/kde3/files/extrapatch-old_configure

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
