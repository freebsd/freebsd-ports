# New ports collection makefile for:    bed
# Date created:         2001/05/07
# Whom:                 jkaltes@hetnet.nl
#
# $FreeBSD$
#

PORTNAME=	bed
PORTVERSION=	0.2.23
CATEGORIES=	editors
MASTER_SITES=	http://bedlinux.tripod.com/download/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Variable dataformat binary editor

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	dep all

OPTIONS=	X11 "Enable X11 support" on

MAN1=		bed.1 xbed.1
MANCOMPRESSED=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
PATCH_DEPENDS+=	rxvt:${PORTSDIR}/x11/rxvt
.endif

# Check for menubar support in "x11/rxvt". In case of failure, disable X11 if
# BATCH or PACKAGE_BUILDING, and IGNORE otherwise.
.if !defined(WITHOUT_X11)
. if exists(${X11BASE}/bin/rxvt)
MENUBAR_TEST!=	rxvt -h 2>&1 | ${GREP} -i menubar || ${TRUE}
.  if empty(MENUBAR_TEST)
.   if defined(BATCH) || defined(PACKAGE_BUILDING)
WITHOUT_X11=	yes
.   else
IGNORE=		needs "x11/rxvt" to be compiled with the WITH_MENUBAR option to enable X11 support
.   endif
.  endif
. endif
.endif

.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	rxvt:${PORTSDIR}/x11/rxvt
PLIST_SUB+=	X11=""
.else
PLIST_SUB+=	X11="@comment "
CONFIGURE_ARGS+=--without-x
.endif

post-configure:
	@${ECHO_CMD} 'CONFIG_DEBUG=n' >> ${WRKSRC}/config
	@${ECHO_CMD} 'CONFIG_MMAP=y' >> ${WRKSRC}/config
	@${ECHO_CMD} 'GCC=${CC}' >> ${WRKSRC}/config

.include <bsd.port.post.mk>
