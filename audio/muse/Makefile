# ex:ts=8
# Ports collection makefile for:	muse
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	MuSE
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.dyne.org/muse/releases/ \
		http://www.ljudmila.org/~jaromil/muse/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple Streaming Engine

LIB_DEPENDS=	mp3lame.0:${PORTSDIR}/audio/lame \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug --disable-lubrify

MAN1=		muse.1
PORTDOCS=	${DOCSFILES:S,doc/,,g}
PLIST_FILES=	bin/muse

CPPFLAGS=	-I${LOCALBASE}/include -DHAVE_DECL_GETOPT -DHAVE_SYS_UIO_H \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

DOCFILES=	AUTHORS ChangeLog KNOWN-BUGS NEWS README TODO doc/USAGE

.if defined(WITHOUT_X11)
PKGNAMESUFFIX=	-nox11
CONFIGURE_ARGS+=	--without-x --with-rubik
.else
USE_GNOME+=	gtk20
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/muse ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/muse.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
