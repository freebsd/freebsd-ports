# New ports collection makefile for:	mpdscribble
# Date created:		July 13 2006
# Whom:			Stepan Zastupov [RedChrom] <redchrom@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mpdscribble
PORTVERSION=	0.17
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd

MAINTAINER=	carpetsmoker@rwxrwxrwx.net
COMMENT=	Musicpd last.fm client

LIB_DEPENDS=	soup:${PORTSDIR}/devel/libsoup

USE_BZIP2=	yes
USE_GNOME=	glib20 pkgconfig
GNU_CONFIGURE=	yes
MAN1=		mpdscribble.1

USE_RC_SUBR=	mpdscribble

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS NEWS
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@[ -f ${PREFIX}/etc/mpdscribble.conf ] || \
		${INSTALL_DATA} ${WRKSRC}/doc/mpdscribble.conf ${PREFIX}/etc/mpdscribble.conf
	@${INSTALL_DATA} ${WRKSRC}/doc/mpdscribble.conf ${PREFIX}/etc/mpdscribble.conf.sample
	@${INSTALL_PROGRAM} ${WRKSRC}/src/mpdscribble ${PREFIX}/bin/mpdscribble
	@${INSTALL_MAN} ${WRKSRC}/doc/mpdscribble.1 ${PREFIX}/man/man1/mpdscribble.1

.include <bsd.port.mk>
