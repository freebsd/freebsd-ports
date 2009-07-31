# New ports collection makefile for:   gimmix
# Date created:                                11 April 2007
# Whom:                                        Matthieu Guegan <matt.guegan@free.fr>
#
# $FreeBSD$
#

PORTNAME=	gimmix
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	gimmix

MAINTAINER=	matt.guegan@free.fr
COMMENT=	Gimmix is a graphical MPD client written in C using GTK+2

LIB_DEPENDS=	mpd:${PORTSDIR}/audio/libmpd \
		tag.6:${PORTSDIR}/audio/taglib \
		nxml:${PORTSDIR}/textproc/libnxml

USE_GNOME=	gtk20 intltool libglade2
USE_BZIP2=	yes

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		gimmix.1

post-patch:
	${LN} -sf ${LOCALBASE}/share/intltool/Makefile.in.in ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's,libmpd-1.0\/libmpd,libmpd,' \
		${WRKSRC}/src/gimmix.h

.include <bsd.port.mk>
