# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MuSE
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://savannah.nongnu.org/download/muse/ \
		http://muse.dyne.org/releases/
DISTNAME=	MuSE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Streaming Engine

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

MAN1=		muse.1

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=.*$$|CFLAGS="\$$CFLAGS"|g ; \
		 s|[$$]GTK_LIBS -lgthread|\$$GTK_LIBS \$$GLIB_LIBS|g ; \
		 s|[$$]GTK_FLAGS|\$$GTK_CFLAGS \$$GLIB_CFLAGS|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-lpthread||g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/muse ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/muse.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog KNOWN-BUGS NEWS README TODO USAGE
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
