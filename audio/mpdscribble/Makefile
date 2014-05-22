# Created by: Stepan Zastupov [RedChrom] <redchrom@gmail.com>
# $FreeBSD$

PORTNAME=	mpdscribble
PORTVERSION=	0.22
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Musicpd last.fm client

LICENSE=	GPLv2

LIB_DEPENDS+=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

USES=		pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_RC_SUBR=	mpdscribble

OPTIONS_DEFINE=	SOUP DOCS
SOUP_DESC=	Use libsoup instead of libcurl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUP}
LIB_DEPENDS+=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup
CONFIGURE_ARGS+=	--with-http-client=soup
.else
LIB_DEPENDS+=	libcurl.so:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-http-client=curl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpdscribble ${STAGEDIR}${PREFIX}/bin/mpdscribble
	${INSTALL_MAN} ${WRKSRC}/doc/mpdscribble.1 ${STAGEDIR}${MANPREFIX}/man/man1/mpdscribble.1
	${INSTALL_DATA} ${WRKSRC}/doc/mpdscribble.conf ${STAGEDIR}${PREFIX}/etc/mpdscribble.conf.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
