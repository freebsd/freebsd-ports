# Ports collection Makefile for:	dasher
# Date created:				5 July 2003
# Whom:					lewiz <purple@lewiz.net>
#
# $FreeBSD$
#   $MCom: ports/accessibility/dasher/Makefile,v 1.66 2009/03/18 04:59:21 marcus Exp $
#

PORTNAME=	dasher
PORTVERSION=	4.10.1
PORTEPOCH=	2
CATEGORIES=	accessibility editors x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Information efficient text-entry interface

BUILD_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian
RUN_DEPENDS=	rarian-sk-config:${PORTSDIR}/textproc/rarian

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier libgnomeui atspi \
		libwnck gnomedocutils
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
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
