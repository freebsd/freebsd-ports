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

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
LIB_DEPENDS+=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient

USES=		pkgconfig tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_RC_SUBR=	mpdscribble

OPTIONS_DEFINE=	SOUP DOCS
SOUP_DESC=	Use libsoup instead of libcurl

SOUP_LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup
SOUP_CONFIGURE_ON=	--with-http-client=soup
SOUP_LIB_DEPENDS_OFF=	libcurl.so:${PORTSDIR}/ftp/curl
SOUP_CONFIGURE_OFF=	--with-http-client=curl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpdscribble ${STAGEDIR}${PREFIX}/bin/mpdscribble
	${INSTALL_MAN} ${WRKSRC}/doc/mpdscribble.1 ${STAGEDIR}${MANPREFIX}/man/man1/mpdscribble.1
	${INSTALL_DATA} ${WRKSRC}/doc/mpdscribble.conf ${STAGEDIR}${PREFIX}/etc/mpdscribble.conf.sample
do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
