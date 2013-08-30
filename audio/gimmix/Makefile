# Created by: Matthieu Guegan <matt.guegan@free.fr>
# $FreeBSD$

PORTNAME=	gimmix
PORTVERSION=	0.5.7.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	gimmix

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gimmix is a graphical MPD client written in C using GTK+2

LIB_DEPENDS=	mpd.4:${PORTSDIR}/audio/libmpd \
		tag.1:${PORTSDIR}/audio/taglib \
		nxml:${PORTSDIR}/textproc/libnxml

LICENSE=	GPLv2

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

USE_GNOME=	gtk20 intltool libglade2
USE_BZIP2=	yes

GNU_CONFIGURE=	yes
USES=		gmake

MAN1=		gimmix.1

CONFIGURE_ENV=	DATADIRNAME=share

.if ${PORT_OPTIONS:MNLS}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CONFIGURE_ARGS+=	--enable-nls
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${LN} -sf ${LOCALBASE}/share/intltool/Makefile.in.in ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/gimmix-covers.c ${WRKSRC}/src/gimmix-lyrics.c

.include <bsd.port.mk>
