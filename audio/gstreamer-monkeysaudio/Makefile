# New ports collection makefile for:	gstreamer monkeysaudio
# Date created:		Thu May 13 14:04:31 CEST 2004
# Whom:			Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#

PORTNAME=	gstreamer
PORTVERSION=	0.8.0
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://gstreamer.freedesktop.org/src/gst${PKGNAMESUFFIX}/
PKGNAMESUFFIX=	-monkeysaudio
DISTNAME=	gst${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GStreamer plugin for monkeysaudio files

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_GNOME=	lthack gnomehack gnomeprefix
USE_GSTREAMER=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
PLIST_SUB=	VERSION="${GST_VERSION}"

GST_VERSION=${PORTVERSION:C/..$//}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/GStreamer-monkeysaudio-permit \
		${DOCSDIR}/GStreamer-monkeysaudio-permit
.endif
# register plugins
	-@${X11BASE}/bin/gst-register-${GST_VERSION} \
		--gst-registry=${PREFIX}/share/gnome/cache/gstreamer-${GST_VERSION}/registry.xml 2>/dev/null

.include <bsd.port.mk>
