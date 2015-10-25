# Created by: Pavel Motyrev <legioner.r@gmail.com>
# $FreeBSD$

PORTNAME=	scmpc
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cdn.bitbucket.org/cmende/${PORTNAME}/downloads/

MAINTAINER=	legioner.r@gmail.com
COMMENT=	Audioscrobbler client for MusicPD

LICENSE=	GPLv2

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
LIB_DEPENDS=	libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libmpdclient.so:${PORTSDIR}/audio/libmpdclient

USES=		tar:bzip2 gmake pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	glib20

PLIST_FILES=	bin/scmpc man/man1/scmpc.1.gz
PORTDOCS=	NEWS README.md scmpc.conf.example

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
