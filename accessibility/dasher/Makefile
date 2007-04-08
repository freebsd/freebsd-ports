# Ports collection Makefile for:	dasher
# Date created:				5 July 2003
# Whom:					lewiz <purple@lewiz.net>
#
# $FreeBSD$
#   $MCom: ports/accessibility/dasher/Makefile,v 1.50 2007/03/12 20:16:34 mezz Exp $
#

PORTNAME=	dasher
PORTVERSION=	4.4.1
PORTEPOCH=	1
CATEGORIES=	accessibility editors x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Information efficient text-entry interface

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

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

.if ${HAVE_GNOME:Mgnomespeech}!=""
USE_GNOME+=	gnomespeech
CONFIGURE_ARGS+=--enable-speech
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2||g'

.include <bsd.port.post.mk>
