# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	1.0.r1
PORTEPOCH=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.vorbis.com/files/rc1/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	naddy@mips.inka.de

LIB_DEPENDS=	ao.1:${PORTSDIR}/audio/libao \
		ogg.2:${PORTSDIR}/audio/libogg \
		vorbis.0:${PORTSDIR}/audio/libvorbis

USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-ao=${LOCALBASE} \
		--with-ogg=${LOCALBASE} \
		--with-vorbis=${LOCALBASE}

MAN1=		ogg123.1 oggenc.1 ogginfo.1

post-extract:
	@(cd ${WRKSRC}/ogg123 ;\
	  ${MV} ogg123rc-example ogg123rc ;\
	  ${PERL} -pi.orig -e 's///' ogg123.1)

.include <bsd.port.mk>
