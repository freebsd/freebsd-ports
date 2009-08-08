# New ports collection makefile for:	mpdscribble
# Date created:		July 13 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpdscribble
PORTVERSION=	0.18
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Musicpd last.fm client

OPTIONS=	SOUP    "Use libsoup for HTTP client library"    off

USE_BZIP2=	yes
USE_GNOME=	glib20 pkgconfig
GNU_CONFIGURE=	yes
MAN1=		mpdscribble.1

USE_RC_SUBR=	mpdscribble

.include <bsd.port.pre.mk>

.if defined(WITH_SOUP)
LIB_DEPENDS+=	soup-2.4.1:${PORTSDIR}/devel/libsoup
CONFIGURE_ARGS+=	--with-http-client=soup
.else
LIB_DEPENDS+=	curl.5:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-http-client=curl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mpdscribble ${PREFIX}/bin/mpdscribble
	${INSTALL_MAN} ${WRKSRC}/doc/mpdscribble.1 ${MANPREFIX}/man/man1/mpdscribble.1
	${INSTALL_DATA} ${WRKSRC}/doc/mpdscribble.conf ${PREFIX}/etc/mpdscribble.conf.sample
.if !exists(${PREFIX}/etc/mpdscribble.conf)
	@(cd ${PREFIX}/etc && ${CP} mpdscribble.conf.sample mpdscribble.conf)
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
