# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/appdata-tools/Makefile 20031 2014-11-02 21:47:55Z kwm $

PORTNAME=	appdata-tools
PORTVERSION=	0.1.8
PORTREVISION=	1
CATEGORIES=	devel
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	AppData is a subset of AppStream

LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup \
		libappstream-glib.so:${PORTSDIR}/devel/appstream-glib

GH_ACCOUNT=	hughsie
GH_TAGNAME=	c1238e3

GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
#CONFIGURE_ARGS=	--enable-introspection=yes
USE_GITHUB=	yes
USES=		autoreconf:build gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gdkpixbuf2 glib20 intltool introspection:build
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-Wclobbered||g ; \
		s|-Wempty-body||g ; \
		s|-Wignored-qualifiers||g ; \
		s|-Wtype-limits||g ; \
		s|-Wmissing-parameter-type||g' \
		${WRKSRC}/configure.ac

pre-configure:
	(cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh)
	${REINPLACE_CMD} 's/DATADIRNAME=lib/DATADIRNAME=share/' \
		${WRKSRC}/configure

.include <bsd.port.mk>
