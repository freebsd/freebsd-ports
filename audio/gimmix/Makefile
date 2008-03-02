# New ports collection makefile for:   gimmix
# Date created:                                11 April 2007
# Whom:                                        Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	gimmix
PORTVERSION=	0.4.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	gimmix

MAINTAINER=	matt.guegan@free.fr
COMMENT=	Gimmix is a graphical MPD client written in C using GTK+2

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		tag.5:${PORTSDIR}/audio/taglib

USE_GNOME=	gtk20 libglade2
USE_BZIP2=	yes

GNU_CONFIGURE=	yes

post-patch:
	${LN} -sf ${LOCALBASE}/share/intltool/intltool-update.in ${WRKSRC}/intltool-update.in
	${LN} -sf ${LOCALBASE}/share/intltool/intltool-merge.in ${WRKSRC}/intltool-merge.in
	${LN} -sf ${LOCALBASE}/share/intltool/intltool-extract.in ${WRKSRC}/intltool-extract.in

.include <bsd.port.mk>
