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

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOMAKE=	yes
WRKSRC=		${WRKDIR}/vorbis

ACLOCAL?=	${LOCALBASE}/bin/aclocal
AUTOHEADER?=	${LOCALBASE}/bin/autoheader
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-ogg=${LOCALBASE}

post-patch:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include <bsd.port.mk>
