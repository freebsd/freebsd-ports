# New ports collection makefile for:	mule
# Version required:	2.2
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.6 1995/01/03 14:16:51 asami Exp $
#

DISTNAME=	mule-2.2
DISTFILES=	emacs-19.28.tar.gz
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
STRIP=
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		  --wnn --wnn-libraries=/usr/X11R6/lib \
		  --wnn-includes=/usr/X11R6/include/wnn --terminal-face
WRKSRC=		${WRKDIR}/emacs-19.28
PATCHFILES=	diff-19.28-2.2.gz
.if !defined(MASTER_SITE_OVERRIDE)
# PATCHSITE=	sh.wide.ad.jp:/JAPAN/mule/
PATCHSITE=	ftp.cs.buffalo.edu:/pub/mule/
.else
PATCHSITE=	${MASTER_SITE_OVERRIDE}
.endif
DEPENDS=	${PORTSDIR}/utils/Wnn
PREPATCH_COOKIE=	${.CURDIR}/work/.prepatch_done
PREBUILD_COOKIE=	${.CURDIR}/work/.prebuild_done

pre-fetch:
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@(cd ${DISTDIR}; \
	 for file in ${PATCHFILES}; do \
		if [ ! -f $$file ]; then \
			echo ">> Fetching patch $$file from remote site...";  \
			${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}$$file; \
	    	fi \
	 done)

pre-patch:	${PREPATCH_COOKIE}

${PREPATCH_COOKIE}:
	@echo "===>  Applying emacs -> mule patch"
	@for file in ${PATCHFILES}; do \
		gzip -c -d ${DISTDIR}/$$file | patch -d ${WRKSRC} -p1 -s; \
	done
	@${TOUCH} ${TOUCH_FLAGS} ${PREPATCH_COOKIE}

pre-build:	${PREBUILD_COOKIE}

${PREBUILD_COOKIE}:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;
	@${TOUCH} ${TOUCH_FLAGS} ${PREBUILD_COOKIE}

.include <bsd.port.mk>
