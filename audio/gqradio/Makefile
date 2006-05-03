# New ports collection makefile for: gqradio
# Date created:		13 Apr 2003
# Whom:			Stefan Jahn <stefan.jahn@nemesis-sektor.de>
#
# $FreeBSD$
#

PORTNAME=	gqradio
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=gqmpeg

MAINTAINER=	stefan.jahn@nemesis-sektor.de
COMMENT=	GTK2 based FM tuner

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 gnomehack gnomeprefix

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
ONLY_FOR_ARCHS=	i386
.else
ONLY_FOR_ARCHS=	alpha i386 ia64
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|share/gqradio|share/gnome/gqradio|; \
		 s|\(doc/gqradio\)-\$$VERSION|\1|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^\(readmedir = \).*|\1$$(prefix)/share/doc/gqradio|; \
		 s|COPYING||' \
		${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
