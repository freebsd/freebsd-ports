# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MuSE
PORTVERSION=	0.8.1
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH} \
		http://muse.dyne.org/releases/
MASTER_SITE_SUBDIR=	muse
DISTNAME=	MuSE-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Streaming Engine

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

MAN1=		muse.1

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x --with-rubik
.else
USE_GNOME+=	gtk12
.endif

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
