# New ports collection makefile for:	gigedit
# Date created:		2008-11-15
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gigedit
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.linuxsampler.org/packages/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	An instrument editor for gig files

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	gig.10:${PORTSDIR}/audio/libgig \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24
RUN_DEPENDS=	${LOCALBASE}/lib/linuxsampler/liblinuxsampler.so.3:${PORTSDIR}/audio/linuxsampler
BUILD_DEPENDS=	${RUN_DEPENDS}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	intltool

.include <bsd.port.mk>
