# New ports collection makefile for:	jamboree
# Date created:			08 Oct 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	jamboree
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	audio gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A simple GNOME music player

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libglade2
USE_GSTREAMER80=	vorbis mad gconf
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		GST_INSPECT="${X11BASE}/bin/gst-inspect-0.8"
GCONF_SCHEMAS=	jamboree.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|^\(@GCONF_SCHEMAS_INSTALL_TRUE@\)        |\1	|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
