# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	muse
PORTVERSION=	0.7.2
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/muse/ \
		http://muse.dyne.org/releases/
DISTNAME=	MuSE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_REINPLACE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
LDFLAGS+=	-lgnugetopt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=.*$$|CFLAGS="\$$CFLAGS"|g ; \
		 s|[$$]GTK_LIBS -lgthread|\$$GTK_LIBS \$$GLIB_LIBS|g ; \
		 s|[$$]GTK_FLAGS|\$$GTK_CFLAGS \$$GLIB_CFLAGS|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muse ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog KNOWN-BUGS NEWS README TODO USAGE
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
