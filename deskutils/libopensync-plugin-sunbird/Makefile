# Created by: Alexander Logvinov <ports@logvinov.com>
# $FreeBSD$

PORTNAME=	libopensync-plugin-sunbird
PORTVERSION=	0.22
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.opensync.org/download/releases/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sunbird plugin for the OpenSync framework

LIB_DEPENDS=	libopensync.so:${PORTSDIR}/devel/libopensync022 \
		libneon.so:${PORTSDIR}/www/neon29

USES=		pkgconfig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 libxml2

PORTDOCS=	AUTHORS COPYING ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
