# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amarok
PORTVERSION=	1.4.10
PORTREVISION=	21
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=	tag.1:${PORTSDIR}/audio/taglib \
		mp4v2.10:${PORTSDIR}/multimedia/mp4v2 \
		xine.2:${PORTSDIR}/multimedia/libxine

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

MIN_OPTIONS_VER=	${PORTNAME}-1.4.1

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_SDL=	sdl
USE_RUBY=	yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	GPOD NJB MTP LIBVISUAL OPENGL AMAZON MYSQL PGSQL HIDEMENUBAR
OPTIONS_DEFAULT=	GPOD NJB MTP OPENGL AMAZON
GPOD_DESC=		Enable Ipod support
NJB_DESC=		Enable Creative Nomad and Dell support
LIBVISUAL_DESC=		Enable libvisual support
AMAZON_DESC=		Enable Amazon cover fetching support
HIDEMENUBAR_DESC=	Revert the 'Hide Menubar' feature

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--without-exscalibar \
		--without-musicbrainz \
		--with-mp4v2 \
		--with-mp4v2-dir=${PREFIX}

CFLAGS+=	-I${LOCALBASE}/include/ruby-${RUBY_VER} -I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}

.if ${PORT_OPTIONS:MGPOD}
LIB_DEPENDS+=	gpod.7:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=--with-libgpod
PLIST_SUB+=	GPOD=""
.else
PLIST_SUB+=	GPOD="@comment "
CONFIGURE_ARGS+=--without-libgpod
.endif

.if ${PORT_OPTIONS:MNJB}
LIB_DEPENDS+=	njb.6:${PORTSDIR}/audio/libnjb
CONFIGURE_ARGS+=--with-libnjb
PLIST_SUB+=	NJB=""
.else
PLIST_SUB+=	NJB="@comment "
.endif

.if ${PORT_OPTIONS:MMTP}
LIB_DEPENDS+=	mtp.9:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--with-libmtp
PLIST_SUB+=	MTP=""
.else
PLIST_SUB+=	MTP="@comment "
.endif

.if ${PORT_OPTIONS:MLIBVISUAL}
LIB_DEPENDS+=	visual-0.4:${PORTSDIR}/graphics/libvisual04
.else
CONFIGURE_ARGS+=--without-libvisual
.endif

.if empty(PORT_OPTIONS:MOPENGL)
CONFIGURE_ARGS+=--without-opengl
.endif

.if empty(PORT_OPTIONS:MAMAZON)
CONFIGURE_ARGS+=--disable-amazon
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
.endif

.if ${PORT_OPTIONS:MPGSQL}
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-postgresql
.endif

.if ${PORT_OPTIONS:MHIDEMENUBAR}
EXTRA_PATCHES=	${PATCHDIR}/hide-main-menu-bar-feature.patch
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug=full
STRIP=		# none
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g;	\
		s|LIBS="-ltunepimp  $$LIBS"|LIBS="-ltunepimp -liconv $$LIBS"|g; \
		s|mp4\.h|mp4v2/mp4v2.h|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in
	@${REINPLACE_CMD} -e 's|<mp4\.h>|<mp4v2/mp4v2.h>|g' \
		${WRKSRC}/amarok/src/metadata/mp4/mp4properties.h \
		${WRKSRC}/amarok/src/metadata/mp4/mp4tag.h
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${TOUCH}

post-install:
.if !empty(PORT_OPTIONS:MMTP) || !empty(PORT_OPTIONS:MNJB) || !empty(PORT_OPTIONS:MGPOD)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
