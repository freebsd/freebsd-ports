# New ports collection makefile for:	xmms-imms
# Date created:				Wed Feb 11 17:11:37 EST 2004
# Whom:					Brian Feldman <green@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imms
PORTVERSION=	1.2a
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	xmms-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic, weight-based playlist ordering plugin for XMMS

BUILD_DEPENDS=	sox:${PORTSDIR}/audio/sox \
		${LOCALBASE}/include/fftw3.h:${PORTSDIR}/math/fftw3
LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		sqlite3:${PORTSDIR}/databases/sqlite3 \
		pcre.0:${PORTSDIR}/devel/pcre \
		fftw3f.4:${PORTSDIR}/math/fftw3-float \
		tag.5:${PORTSDIR}/audio/taglib

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoheader:259 autoconf:259
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile
.endif

.if ${OSVERSION} < 500000
BROKEN=		Does not compile
.endif

post-patch:
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g' ${WRKSRC}/vars.mk.in
.if ${OSVERSION} < 500000
	@cd ${WRKSRC} && \
	    ${REINPLACE_CMD} 's:#include.<stdint\.h>:#include <sys/types.h>:' \
		players/xmms/plugin.h analyzer/spectrum.h analyzer/analyzer.cc
.endif

.include <bsd.port.post.mk>
