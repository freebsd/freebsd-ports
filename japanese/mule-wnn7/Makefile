# New ports collection makefile for:	mule
# Version required:	2.2.2
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.13 1995/04/01 12:44:49 jkh Exp $
#

DISTNAME=	mule-2.2.2
CATEGORIES+=	editors
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/
DISTFILES=	emacs-19.28.tar.gz

# Use one of these if you are in Japan

# PATCHSITE=	sh.wide.ad.jp:/JAPAN/mule/
# PATCHSITE=	etlport.etl.go.jp:/pub/mule/

PATCH_SITES=	ftp.cs.buffalo.edu:/pub/mule/
PATCHFILES=	diff-19.28-2.2.gz patch-2.2.1.gz patch-2.2.2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	asami@FreeBSD.ORG

.if !exists(/usr/X11R6/lib/libwnn.a)
DEPENDS=	${PORTSDIR}/utils/Wnn
.endif

WRKSRC=		${WRKDIR}/emacs-19.28
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		  --wnn --wnn-libraries=/usr/X11R6/lib \
		  --wnn-includes=/usr/X11R6/include/wnn --terminal-face
STRIP=

PREBUILD_COOKIE=	${.CURDIR}/work/.prebuild_done

pre-build:	${PREBUILD_COOKIE}

${PREBUILD_COOKIE}:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;
	@${TOUCH} ${TOUCH_FLAGS} ${PREBUILD_COOKIE}

.include <bsd.port.mk>
