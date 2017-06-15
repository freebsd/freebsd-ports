# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	xwota
PORTVERSION=	0.4
PORTREVISION=	8
CATEGORIES=	comms hamradio
MASTER_SITES=	http://people.fabaris.it/iz0ete/xwota/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	X version of who is on the air

LICENSE=	GPLv2

USES=		gmake pkgconfig libtool
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

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
