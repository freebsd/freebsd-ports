# New ports collection makefile for:	libvorbis
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	libvorbis
PORTVERSION=	20001018
CATEGORIES=	audio
MASTER_SITES=	http://home.student.utwente.nl/t.vanklaveren/distfiles/
DISTNAME=	vorbis-${PORTVERSION}

MAINTAINER=	t.vanklaveren@student.utwente.nl

LIB_DEPENDS=	ogg.0:${PORTSDIR}/audio/libogg

WRKSRC=		${WRKDIR}/vorbis

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
CONFIGURE_ARGS=	--with-ogg=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
AUTOMAKE_ARGS=	--add-missing
AUTOCONF_ARGS=	; ${PERL} -pi -e 's|-lpthread|-pthread|g' ${WRKSRC}/configure

AUTOHEADER?=	${LOCALBASE}/bin/autoheader

pre-configre:
	cd ${WRKSRC} && ${AUTOHEADER}

.include <bsd.port.mk>
