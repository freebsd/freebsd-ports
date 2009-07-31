# New ports collection makefile for:	deskutils/multi-backgrounds-daemon
# Date created:				16 Jul 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$

PORTNAME=	multi-backgrounds-daemon
PORTVERSION=	0.1.1
PORTREVISION=	9
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://jeanschu.free.fr/multi-backgrounds-daemon/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change your GNOME2 backgound when you switch to other workspace

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui libwnck
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ;' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
