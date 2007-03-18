# New ports collection makefile for:	amarok
# Date created:			Tue Feb 24 02:21:14 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	amarok
PORTVERSION=	1.4.5
PORTREVISION=	5
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	mich@FreeBSD.org
COMMENT=	Media player for KDE

LIB_DEPENDS=	tag.5:${PORTSDIR}/audio/taglib \
		tunepimp.5:${PORTSDIR}/audio/libtunepimp \
		mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2 \
		xine.1:${PORTSDIR}/multimedia/libxine

MIN_OPTIONS_VER=	${PORTNAME}-1.4.1

USE_BZIP2=	yes
USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_SDL=	sdl
USE_RUBY=	yes
USE_LDCONFIG=	yes

OPTIONS=	GPOD "iPod support" on \
		NJB "Creative Nomad and Dell support" on \
		MTP "MTP device support" on \
		OPENGL "OpenGL support" on \
		AMAZON "Amazon cover fetching support" on \
		MYSQL "Use MySQL as collection backend" off \
		POSTGRESQL "Use PostgreSQL as collection backend" off \

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_PATCHES+=	${PATCHDIR}/extra-amarok_src_expression.h
.endif

CONFIGURE_ARGS+=--without-exscalibar \
		--with-mp4v2 \
		--with-mp4v2-dir=${PREFIX} \
		--without-libvisual

.if !defined(WITH_GPOD)
PLIST_SUB+=	GPOD="@comment "
CONFIGURE_ARGS+=--without-libgpod
.else
LIB_DEPENDS+=	gpod.1:${PORTSDIR}/audio/libgpod
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
LIB_DEPENDS+=	mtp.7:${PORTSDIR}/audio/libmtp
CONFIGURE_ARGS+=--with-libmtp
PLIST_SUB+=	MTP=""
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

.if defined(DEBUG)
CONFIGURE_ARGS+=--enable-debug=full
STRIP=          # none
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
