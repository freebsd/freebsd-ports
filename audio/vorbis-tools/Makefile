# New ports collection makefile for:	vorbis-tools
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-tools
PORTVERSION=	20001018
CATEGORIES=	audio
MASTER_SITES=	http://home.student.utwente.nl/t.vanklaveren/distfiles/
DISTNAME=	vorbis-tools-${PORTVERSION}

MAINTAINER=	t.vanklaveren@student.utwente.nl

LIB_DEPENDS=	ao.0:${PORTSDIR}/audio/libao \
		ogg.0:${PORTSDIR}/audio/libogg \
		vorbis.0:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/vorbis-tools
ACLOCAL?=	${LOCALBASE}/bin/aclocal
AUTOHEADER?=	${LOCALBASE}/bin/autoheader
CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=	--with-ogg=${LOCALBASE} \
			--with-ao=${LOCALBASE}

MAN1=		ogg123.1

post-build:
# This is probably evil, and should be in a Makefile.
	cd ${WRKSRC}/oggenc && ${CC} ${CFLAGS} -c getopt1.c
	cd ${WRKSRC}/ogg123 && ${CC} ${CFLAGS} -c ogg123.c -I../oggenc -I${LOCALBASE}/include 
	cd ${WRKSRC}/ogg123 && ${CC} ${LDFLAGS} -o ogg123 ogg123.o ../oggenc/getopt.o ../oggenc/getopt1.o -L${LOCALBASE}/lib -logg -lvorbis -lao -lvorbisfile

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ogg123/ogg123 ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/ogg123/ogg123.1 ${PREFIX}/man/man1/

post-patch:
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOHEADER}
	cd ${WRKSRC} && ${AUTOMAKE} --add-missing
	cd ${WRKSRC} && ${AUTOCONF}

.include <bsd.port.mk>
