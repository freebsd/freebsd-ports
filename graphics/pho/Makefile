# New ports collection makefile for:	pho
# Date created:				10 April 2003
# Whom:					Roland Jesse <roland.jesse@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	pho
DISTVERSION=	0.9.7-pre7
CATEGORIES=	graphics
MASTER_SITES=	http://shallowsky.com/software/pho/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight image viewer

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_GNOME=	gtk20
MAKE_ARGS=	INSTALLPREFIX="${PREFIX}"
ALL_TARGET=	pho
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		pho.1
PLIST_FILES=	bin/pho

post-patch:
	@${REINPLACE_CMD} -e 's|make|$$(MAKE)| ; \
		s|$$(INSTALL) \(pho \)|${INSTALL_PROGRAM} \1| ; \
		s|$$(INSTALL) \(pho\.1\)|${INSTALL_MAN} \1| ; \
		s|-g|${CFLAGS}| ; s|^G1FLAGS|#&|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-Wall -g -O2 ||' ${WRKSRC}/exif/Makefile

.include <bsd.port.mk>
