# New ports collection makefile for:	xmms-imms
# Date created:				Wed Feb 11 17:11:37 EST 2004
# Whom:					Brian Feldman <green@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imms
PORTVERSION=	1.2a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	green@FreeBSD.org
COMMENT=	Automatic, weight-based playlist ordering plugin for XMMS

BUILD_DEPENDS=	sox:${PORTSDIR}/audio/sox
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		pcre.0:${PORTSDIR}/devel/pcre \
		fftw3f.3:${PORTSDIR}/math/fftw3-float \
		tag.4:${PORTSDIR}/audio/taglib

BROKEN=		Does not compile
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_REINPLACE=	yes

post-patch:
	@cd ${WRKSRC} && \
	    ${REINPLACE_CMD} 's:#include.<stdint\.h>:#include <sys/types.h>:' \
		players/xmms/plugin.h analyzer/spectrum.h analyzer/analyzer.cc
.endif

.include <bsd.port.post.mk>
