# New ports collection makefile for:    bed
# Date created:         2001/05/07
# Whom:                 jkaltes@hetnet.nl
#
# $FreeBSD$
#

PORTNAME=	bed
PORTVERSION=	0.2.19
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/editors/terminal
EXTRACT_SUFX=		.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Variable dataformat binary editor

# Cannot guarantee rxvt will have menubar enabled on bento.
.if defined(PACKAGE_BUILDING)
WITHOUT_X11=	yes
.endif

BUILD_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash2
.if !defined(WITHOUT_X11)
PATCH_DEPENDS+=	${X11BASE}/bin/rxvt:${PORTSDIR}/x11/rxvt
RUN_DEPENDS=	${X11BASE}/bin/rxvt:${PORTSDIR}/x11/rxvt
.endif

GNU_CONFIGURE=	yes

USE_GMAKE=	yes

MAN1=		bed.1 xbed.1
MANCOMPRESSED=	yes

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-x
PLIST_SUB+=		X11="@comment "
.else
PLIST_SUB+=		X11=""

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-configure:
	@if "${X11BASE}/bin/rxvt" -h 2>&1 | ${GREP} -qi menubar; then \
	else \
		${ECHO_MSG} "${PORTSDIR}/x11/rxvt must be compiled with the option"; \
		${ECHO_MSG} "	WITH_MENUBAR=yes"; \
		${ECHO_MSG} "to enable X11 support."; \
		exit 1; \
	fi
.endif
.endif

post-configure:
	${ECHO_MSG} 'CONFIG_DEBUG=n' >> ${WRKSRC}/config
	${ECHO_MSG} 'CONFIG_MMAP=y' >> ${WRKSRC}/config
	${GMAKE} -C ${WRKSRC} dep

.include <bsd.port.mk>
