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

LIB_DEPENDS+=	mpdclient.2:${PORTSDIR}/audio/libmpdclient

USE_BZIP2=	yes
USE_GNOME=	glib20 pkgconfig
GNU_CONFIGURE=	yes
USE_RC_SUBR=	mpdscribble

MAN1=		mpdscribble.1

OPTIONS_DEFINE=	SOUP DOCS
SOUP_DESC=	Use libsoup instead of libcurl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUP}
LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup
CONFIGURE_ARGS+=	--with-http-client=soup
.else
LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-http-client=curl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpdscribble ${PREFIX}/bin/mpdscribble
	${INSTALL_MAN} ${WRKSRC}/doc/mpdscribble.1 ${MANPREFIX}/man/man1/mpdscribble.1
	${INSTALL_DATA} ${WRKSRC}/doc/mpdscribble.conf ${PREFIX}/etc/mpdscribble.conf.sample
.if !exists(${PREFIX}/etc/mpdscribble.conf)
	@(cd ${PREFIX}/etc && ${CP} mpdscribble.conf.sample mpdscribble.conf)
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
