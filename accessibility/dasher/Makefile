# Ports collection Makefile for:	dasher
# Date created:				5 July 2003
# Whom:					lewiz <purple@lewiz.net>
#
# $FreeBSD$
#   $MCom: ports/accessibility/dasher/Makefile,v 1.61 2007/11/15 20:54:19 marcus Exp $
#

PORTNAME=	dasher
PORTVERSION=	4.7.0
PORTEPOCH=	1
CATEGORIES=	accessibility editors x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Information efficient text-entry interface

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier libgnomeui atspi \
		libwnck gnomedocutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_GCC=	3.4+
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	dasher.schemas
MAN1=		dasher.1

.include <bsd.port.pre.mk>

#.if ${HAVE_GNOME:Mgnomespeech}!=""
#USE_GNOME+=	gnomespeech
#CONFIGURE_ARGS+=--enable-speech
#.endif
CONFIGURE_ARGS+=	--disable-speech

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2||g'
.if ${OSVERSION} >= 700042
	@${REINPLACE_CMD} -e 's|__gnu_cxx::lldiv|lldiv|' \
	    	${WRKSRC}/Src/DasherCore/DasherViewSquare.cpp
.endif

.include <bsd.port.post.mk>
