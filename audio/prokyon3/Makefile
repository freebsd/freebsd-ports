# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	prokyon3
PORTVERSION=	0.9.6
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multithreaded music manager and tag editor

BUILD_DEPENDS=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin \
		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		mad:${PORTSDIR}/audio/libmad \
		vorbis:${PORTSDIR}/audio/libvorbis \
		tag:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	${LOCALBASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin

DEPRECATED=	Depends on Qt3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_XORG=	x11 xft
USE_QT_VER=	3
USE_MYSQL=	yes
USE_PERL5_BUILD=yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-other-includes=${LOCALBASE}/include \
		--with-other-libs=${LOCALBASE}/lib \
		--without-mixxx --without-musicextras \
		--without-musicbrainz
MAKE_ARGS=	LIBS="-lqt-mt ${PTHREAD_LIBS}"

.include <bsd.port.pre.mk>

.if defined(WITH_BURN)
USE_CDRTOOLS=	yes
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		normalize:${PORTSDIR}/audio/normalize \
		bash:${PORTSDIR}/shells/bash
PLIST_SUB+=	BURN=""
.else
PLIST_SUB+=	BURN="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^#!.*$$|#!${LOCALBASE}/bin/bash|g ; \
		 s|^CXXFLAGS=|#CXXFLAGS=|g ; \
		 s|^CFLAGS=|#CFLAGS=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^#!.*$$|#!${LOCALBASE}/bin/bash|g' ${WRKSRC}/prokburn
	@${REINPLACE_CMD} -e \
		's|: install-binSCRIPTS|:|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|getopt.$$(OBJEXT)||g' ${WRKSRC}/src/Makefile.in

post-install:
.if defined(WITH_BURN)
	${INSTALL_SCRIPT} ${WRKSRC}/prokburn ${PREFIX}/bin
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
