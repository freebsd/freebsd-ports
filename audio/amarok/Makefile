# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	1.4.10
PORTREVISION=	4
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=	tag.6:${PORTSDIR}/audio/taglib \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		xine.1:${PORTSDIR}/multimedia/libxine

MIN_OPTIONS_VER=	${PORTNAME}-1.4.1

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_GETTEXT=	yes
USE_SDL=	sdl
USE_RUBY=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

OPTIONS=	GPOD "iPod support" on \
		NJB "Creative Nomad and Dell support" on \
		MTP "MTP device support" on \
		LIBVISUAL "libvisual support" off \
		OPENGL "OpenGL support" on \
		AMAZON "Amazon cover fetching support" on \
		MYSQL "Use MySQL as collection backend" off \
		POSTGRESQL "Use PostgreSQL as collection backend" off \
		HIDEMENUBAR "Revert the 'Hide Menubar' feature" off \

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--without-exscalibar \
		--with-mp4v2 \
		--with-mp4v2-dir=${PREFIX}

.if !defined(WITH_GPOD)
PLIST_SUB+=	GPOD="@comment "
CONFIGURE_ARGS+=--without-libgpod
.else
LIB_DEPENDS+=	gpod.3:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=--with-libgpod
PLIST_SUB+=	GPOD=""
.endif

.if !defined(WITH_NJB)
PLIST_SUB+=	NJB="@comment "
.else
LIB_DEPENDS+=	njb.6:${PORTSDIR}/audio/libnjb
CONFIGURE_ARGS+=--with-libnjb
PLIST_SUB+=	NJB=""
.endif

.if !defined(WITH_MTP)
PLIST_SUB+=	MTP="@comment "
.else
LIB_DEPENDS+=	mtp.8:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--with-libmtp
PLIST_SUB+=	MTP=""
.endif

.if defined(WITHOUT_LIBVISUAL)
CONFIGURE_ARGS+=--without-libvisual
.else
LIB_DEPENDS+=	visual-0.4:${PORTSDIR}/graphics/libvisual04
.endif

.if defined(WITHOUT_OPENGL)
CONFIGURE_ARGS+=--without-opengl
.endif

.if defined(WITHOUT_AMAZON)
CONFIGURE_ARGS+=--disable-amazon
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
CONFIGURE_ARGS+=--enable-mysql
.endif

.if defined(WITH_POSTGRESQL)
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-postgresql
.endif

.if defined(WITH_HIDEMENUBAR)
EXTRA_PATCHES=	${PATCHDIR}/hide-main-menu-bar-feature.patch
.endif

.if defined(DEBUG)
CONFIGURE_ARGS+=--enable-debug=full
STRIP=		# none
.endif

pre-extract:	check-options-version

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|LIBS="-ltunepimp  $$LIBS"|LIBS="-ltunepimp -liconv $$LIBS"|g' \
	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${TOUCH}

post-install:
.if defined(WITH_MTP) || defined(WITH_NJB) || defined(WITH_GPOD)
	@${CAT} ${PKGMESSAGE}
.endif

check-options-version:
.ifdef(_OPTIONS_READ)
	@(if ${PKG_VERSION} -t ${_OPTIONS_READ} ${MIN_OPTIONS_VER} | ${GREP} -q '<'; \
	 then	${ECHO_CMD} ""; \
		${ECHO_CMD} "===> You have unsupported (old) OPTIONS, please do a 'make rmconfig; make'"; \
		${ECHO_CMD} ""; \
		exit 1; \
	fi)
.endif

.include <bsd.port.post.mk>
