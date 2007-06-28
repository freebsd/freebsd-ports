# New ports collection makefile for:           prokyon3
# Date created:                                11 November 2002
# Whom:                                        Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	prokyon3
PORTVERSION=	0.9.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Prokyon3 is a multithreaded MP3 manager and tag editor

BUILD_DEPENDS=	${X11BASE}/lib/plugins/sqldrivers/libqsqlmysql.so:${PORTSDIR}/databases/qt-mysql-plugin
LIB_DEPENDS=	id3-3.8:${PORTSDIR}/audio/id3lib \
		vorbis.3:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

USE_QT_VER=	3
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
USE_GETTEXT=	yes
USE_MYSQL=	yes
CONFIGURE_ARGS+=--with-qtdir=${X11BASE} --with-id3-libs=${LOCALBASE}\
	 	--with-ogg-libs=${LOCALBASE} --with-vorbis-libs=${LOCALBASE} \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include \
		-I${QT_PREFIX}/include" LDFLAGS="${LDFLAGS}"
LDFLAGS+=	-L${LOCALBASE}/lib

.if defined(WITH_BURN)
USE_CDRTOOLS=	yes
RUN_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123 \
		ogg123:${PORTSDIR}/audio/vorbis-tools \
		normalize:${PORTSDIR}/audio/normalize \
		bash:${PORTSDIR}/shells/bash
PLIST_FILES+=	bin/prokburn
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g -O2|${CFLAGS}|; s|-lqt-mt|-lqt-mt ${PTHREAD_LIBS}|' ${WRKSRC}/configure
.if !defined(WITH_BURN)
	@${REINPLACE_CMD} -e 's|prokburn||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's|prokburn||' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -E 's|[[:alpha:]]+::||' ${WRKSRC}/src/gui.h \
		${WRKSRC}/src/configuration.h
	@${REINPLACE_CMD} -e 's|QProgressDialogScroll::||' \
		${WRKSRC}/src/jobbase.cpp

post-install:
	@${CAT} ${PKGMESSAGE}
	@sleep 5

.include <bsd.port.mk>
