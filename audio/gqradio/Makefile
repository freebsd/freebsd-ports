# New ports collection makefile for: gqradio
# Date created:		13 Apr 2003
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gqradio
PORTVERSION=	1.9.2
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF/gqmpeg/${PORTNAME}/${PORTVERSION}

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	GTK2 based FM tuner

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomehack gnomeprefix

ONLY_FOR_ARCHS=	alpha i386 ia64

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

post-patch:
	@${REINPLACE_CMD} -e 's|\(doc/gqradio\)-\$$VERSION|\1|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^\(readmedir = \).*|\1$$(prefix)/share/doc/gqradio|; \
		 s|COPYING||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
