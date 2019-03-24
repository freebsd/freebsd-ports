# Created by: Sean Bruno <sbruno@freebsd.org>
# $FreeBSD$

PORTNAME=	libshout-idjc
PORTVERSION=	2.4.2
CATEGORIES=	audio python
MASTER_SITES=	SF/libshoutidjc.idjc.p

MAINTAINER=	sbruno@FreeBSD.org
COMMENT=	Shoutcast/Icecast Library for audio/idjc

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
		libvorbis.so:audio/libvorbis \
		libogg.so:audio/libogg \
		libspeex.so:audio/speex

GNU_CONFIGURE=	yes
USES=		libtool pathfix pkgconfig autoreconf
USE_LDCONFIG=	yes
LDFLAGS+=       -lcrypto -L${LOCALBASE}/lib -logg

OPTIONS_DEFINE=	DOCS

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} '/_XOPEN_SOURCE/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} '/^doc_DATA =/ s|COPYING||' ${WRKSRC}/Makefile.am
	@${MV} ${WRKSRC}/m4/shout.m4 ${WRKSRC}/m4/shout-idjc.m4
	@${REINPLACE_CMD} '/^EXTRA_DIST =/ s|shout.m4|shout-idjc.m4|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} '/^m4data_DATA =/ s|shout.m4|shout-idjc.m4|' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} '/^ckportdir = .*/d' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} '/^ckport_DATA = .*/d' ${WRKSRC}/Makefile.am


.include <bsd.port.mk>
