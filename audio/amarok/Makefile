# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	1.4.0a
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		tunepimp:${PORTSDIR}/audio/libtunepimp \
		mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		xine.15:${PORTSDIR}/multimedia/libxine

MIN_OPTIONS_VER=	${PORTNAME}-1.4.0a

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl
USE_RUBY=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-1.4.0

OPTIONS=	GPOD "iPod support" on \
		XMMS "XMMS visualizations" off \
		LIBVISUAL "libvisual support" off \
		OPENGL "OpenGL support" on \
		AMAZON "Amazon cover fetching support" on \
		MYSQL "Use MySQL as collection backend" off \
		POSTGRESQL "Use PostgreSQL as collection backend" off \

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=--without-exscalibar \
		--with-mp4v2 \
		--with-mp4v2-dir=${PREFIX}

.if !defined(WITH_GPOD)
PLIST_SUB+=	GPOD="@comment "
.else
LIB_DEPENDS+=	gpod.302:${PORTSDIR}/audio/libgpod
CONFIGURE_ARGS+=--with-libgpod
PLIST_SUB+=	GPOD=""
.endif

.if !defined(WITH_XMMS)
PLIST_SUB+=	XMMS="@comment "
CONFIGURE_ARGS+=--without-xmms
.else
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/multimedia/xmms
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.endif

.if !defined(WITH_LIBVISUAL)
PLIST_SUB+=	LIBVISUAL="@comment "
CONFIGURE_ARGS+=--without-libvisual
.else
LIB_DEPENDS+=	visual.0:${PORTSDIR}/graphics/libvisual
PLIST_SUB+=	LIBVISUAL=""
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

pre-extract:	check-options-version

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g'	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|LIBS="-ltunepimp  $$LIBS"|LIBS="-ltunepimp -liconv $$LIBS"|g' \
	${WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} -e 's|xx||g' ${WRKSRC}/po/Makefile.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${TOUCH}

post-install:
.if defined(WITH_LIBVISUAL)
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
