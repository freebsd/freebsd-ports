# ex:ts=8
# New ports collection makefile for:	adgali
# Date created:			Sep 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	adgali
PORTVERSION=	0.1.0
PORTREVISION=	1
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12 \
		jpeg:${PORTSDIR}/graphics/jpeg \
		tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_FREETYPE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-compile-type=optim
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's|-O3 ||g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
