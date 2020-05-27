# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	gimmix
PORTVERSION=	0.5.7.2
CATEGORIES=	audio
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical MPD client written in C using GTK2

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpd.so:audio/libmpd \
		libtag.so:audio/taglib \
		libnxml.so:textproc/libnxml

USES=		desktop-file-utils gmake gnome pkgconfig tar:bzip2
USE_GNOME=	gtk20 intltool libglade2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	DATADIRNAME=share

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CPPFLAGS=	-I${LOCALBASE}/include
NLS_LDFLAGS=	-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext
NLS_USES_OFF=		gettext-tools

post-patch:
	@${LN} -sf ${LOCALBASE}/share/intltool/Makefile.in.in ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/gimmix-covers.c ${WRKSRC}/src/gimmix-lyrics.c

.include <bsd.port.mk>
