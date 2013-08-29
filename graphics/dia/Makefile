# Created by: saper@system.pl
# $FreeBSD$
#   $MCom: ports/graphics/dia/Makefile,v 1.16 2007/10/11 02:49:12 mezz Exp $

PORTNAME=	dia
DISTVERSION=	0.97.2
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Diagram creation program, similar to Visio

LIB_DEPENDS=	libpopt.so:${PORTSDIR}/devel/popt \
		libpng15.so:${PORTSDIR}/graphics/png

USES=		desktop-file-utils gettext gmake pathfix
USE_XZ=		yes
USE_GNOME=	gtk20 gnomeprefix libxslt libartlgpl2 intlhack
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LOCALBASE="${LOCALBASE}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--disable-gnome

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl
MAN1=		dia.1
MANLANG=	"" fr
.endif

#.if !defined(WITHOUT_PYTHON)
#USE_PYTHON=	yes
#USE_GNOME+=	pygtk2
#CONFIGURE_ARGS=	--with-python
#PLIST_SUB+=	PYTHON=""
#.else
#PLIST_SUB+=	PYTHON="@comment "
#.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
LIB_DEPENDS+=		libEMF.so:${PORTSDIR}/graphics/libemf
CONFIGURE_ARGS+=	--enable-libemf
PLIST_SUB+=		WMF=""
.else
CONFIGURE_ARGS+=	--disable-libemf
PLIST_SUB+=		WMF="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/lib/intl.c
	@${REINPLACE_CMD} -e 's|glib/gstrfuncs.h>|glib.h>|g' \
		-e 's|glib/gtestutils.h|glib.h|g' \
		${WRKSRC}/objects/custom/shape_typeinfo.c \
		${WRKSRC}/tests/test-objects.c \
		${WRKSRC}/tests/test-boundingbox.c
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/SUBDIRS/s|data doc tests|data tests|g' \
		${WRKSRC}/Makefile.in
.endif
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} -e \
		's,\(^GTK_LIBS.*\),\1 ${PTHREAD_LIBS}, ; \
		 s,\(^GTK_CFLAGS = \),\1 ${PTHREAD_CFLAGS} ,'
	@${REINPLACE_CMD} -e 's|http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl|${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl| ; \
		s|echo aout|echo elf|g ; s|/usr/include/libEMF|${LOCALBASE}/include/libEMF|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
