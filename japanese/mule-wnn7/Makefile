# New ports collection makefile for:	mule
# Version required:	2.2.2
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.16 1995/04/20 18:23:06 asami Exp $
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
DEPENDS=	${PORTSDIR}/japanese/Wnn
.endif

WRKSRC=		${WRKDIR}/emacs-19.28
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		  --wnn --wnn-libraries=/usr/X11R6/lib \
		  --wnn-includes=/usr/X11R6/include/wnn --terminal-face
STRIP=

pre-build:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;

post-install:
# note that any2ps is a script
	strip ${PREFIX}/bin/mule-19.28
	strip ${PREFIX}/bin/m2ps
	strip ${PREFIX}/bin/b2m
	strip ${PREFIX}/bin/coco

.include <bsd.port.mk>
