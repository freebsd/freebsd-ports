# New ports collection makefile for:	clanlib
# Date created:				10 May 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	clanlib
PORTVERSION=	0.6.5.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	http://clanlib.org/~sphair/download/ \
		http://freebsd.nsu.ru/distfiles/
DISTNAME=	ClanLib-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	Cross-platform game SDK

LIB_DEPENDS=	Hermes:${PORTSDIR}/graphics/Hermes \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		mikmod:${PORTSDIR}/audio/libmikmod \
		vorbis:${PORTSDIR}/audio/libvorbis

# conflicts with devel/clanlib-devel
CONFLICTS=	clanlib-0.7.*

WRKSRC=		${WRKDIR}/ClanLib-${PORTVERSION:R}

USE_XLIB=	yes
USE_GL=		yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-directfb --disable-lua
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
USE_PERL5_BUILD=	yes
ALL_TARGET=	all docs
INSTALL_TARGET=	install docs_install
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/Sources/TTF/font_ttf.cpp
	@${REINPLACE_CMD} -e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|; s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|' \
		${WRKSRC}/Setup/Unix/clanlib-config.in
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL}|' \
		${WRKSRC}/Documentation/FAQ.theme \
		${WRKSRC}/Documentation/Reference/pce2 \
		${WRKSRC}/Documentation/Utilities/transform.sh
	@${REINPLACE_CMD} -e 's|@perl_exec@|${PERL}|' \
		${WRKSRC}/Documentation/Utilities/webbuilder.pl.in

.include <bsd.port.mk>
