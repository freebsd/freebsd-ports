# New ports collection makefile for:	ccaudio2
# Date created:	13 February 2008
# Whom:		gahr
#
# $FreeBSD$
#

PORTNAME=	ccaudio2
PORTVERSION=	0.9.14
CATEGORIES=	audio
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	ccgnu2:${PORTSDIR}/devel/commoncpp

CONFLICTS=	ccaudio-[0-9]*

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	audiotool.1 tonetool.1

post-patch:
	${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
