# New ports collection makefile for:	GNOME Music Quiz
# Date created:			20 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	gnome-music-quiz
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	games audio
MASTER_SITES=	http://ishamael.tunkeymicket.com/tarballs/
DISTNAME=	mq-${PORTVERSION}

MAINTAINER=	jylefort@brutele.be
COMMENT=	A game similar to the television show 'Name That Tune'

RUN_DEPENDS=	rhythmbox:${PORTSDIR}/audio/rhythmbox

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix libgnomeui gstreamerplugins
USE_LIBTOOL_VER=	15

pre-configure:
	@${RM} -f \
		${WRKSRC}/intltool-extract.in \
		${WRKSRC}/intltool-merge.in \
		${WRKSRC}/intltool-update.in
	@${CP} -f \
		${LOCALBASE}/share/intltool/intltool-extract.in \
		${LOCALBASE}/share/intltool/intltool-merge.in \
		${LOCALBASE}/share/intltool/intltool-update.in \
		${WRKSRC}

.include <bsd.port.mk>
