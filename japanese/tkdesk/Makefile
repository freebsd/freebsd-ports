# New ports collection makefile for:	tkdesk
# Date created:         21 Sep 1999
# Whom:                 Yoichi ASAI <yatt@msc.biglobe.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	tkdesk
PORTVERSION=	${VERSION}${VERSION_PL}
PORTREVISION=	1
CATEGORIES=	japanese x11-fm
MASTER_SITES=	# disappeared
DISTNAME=	${PORTNAME}-${VERSION}

PATCH_SITES=	# disappeared
PATCHFILES=	tkdesk-${VERSION}-jmenu-${VERSION_PL}.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical, highly configurable and powerful file manager

BROKEN=		"mastersite disappeared"
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=	2005-12-09

LIB_DEPENDS=	tk42jp.1:${PORTSDIR}/japanese/tk42
RUN_DEPENDS=	imali:${PORTSDIR}/mail/im \
		easypr:${PORTSDIR}/japanese/easypr

VERSION=	1.1
VERSION_PL=	p58

USE_XLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	TCLCONF_PATH=${LOCALBASE}/lib/tcl7.6jp
CONFIGURE_ENV+=	TKCONF_PATH=${LOCALBASE}/lib/tk4.2jp

MAN1=		tkdesk.1 cd-tkdesk.1 ed-tkdesk.1 od-tkdesk.1

pre-patch:
	@cd ${WRKSRC}; ${PATCH} -s < ${FILESDIR}/pre-patch

post-patch:
	@${FIND} ${WRKSRC}/tcldesk '(' -name '*.orig' -o -name '*~' ')' \
	-exec ${RM} -f {} \;
	@${RM} ${WRKSRC}/config.h ${WRKSRC}/config.cache

post-install:
	@/usr/bin/strip ${PREFIX}/bin/tkdesksh
	@/usr/bin/strip ${PREFIX}/bin/tkdeskclient

.include <bsd.port.mk>
