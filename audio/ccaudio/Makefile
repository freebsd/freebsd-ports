# New ports collection makefile for:	ccaudio
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccaudio
PORTVERSION=	1.2.0
CATEGORIES=	audio
MASTER_SITES=	SF/gnutelephony/production/1.2.16

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	ccgnu2:${PORTSDIR}/devel/commoncpp

BROKEN=		Does not build with libtool 2.2.
DEPRECATED=	has been broken for 4 months
EXPIRATION_DATE=2010-01-08

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|<stdint\.h>|<stdlib.h>|g' ${WRKSRC}/src/dtmf.cpp
	@${REINPLACE_CMD} -e \
		's|@CXXFLAGS@|& $$(g_711_CXXFLAGS)|' ${WRKSRC}/dso/Makefile.in

.include <bsd.port.mk>
