# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	xwota
PORTVERSION=	0.4
PORTREVISION=	7
CATEGORIES=	comms hamradio
MASTER_SITES=	http://people.fabaris.it/iz0ete/xwota/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	X version of who is on the air

LICENSE=	GPLv2

USES=		gmake pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for	d in ${WRKSRC}/README \
	${WRKSRC}/COPYING \
	${WRKSRC}/AUTHORS \
	${WRKSRC}/ChangeLog \
	${WRKSRC}/INSTALL \
	${WRKSRC}/NEWS \
	${WRKSRC}/TODO
	@${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
