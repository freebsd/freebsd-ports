# New ports collection makefile for:	mule
# Version required:	2.1
# Date created:		22 November 1994
# Whom:			Satoshi Asami (asami)
#
# $Id: Makefile,v 1.3 1994/11/26 23:07:02 ats Exp $
#

DISTNAME=	mule-2.1
DISTFILES=	emacs-19.27.tar.gz
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	i386--freebsd --prefix=${PREFIX} --with-x-toolkit \
		  --wnn --wnn-libraries=/usr/X11R6/lib \
		  --wnn-includes=/usr/X11R6/include/wnn --terminal-face
WRKSRC=		${WRKDIR}/emacs-19.27
PATCHFILES=	diff-19.27-2.1.gz
.if !defined(MASTER_SITE_OVERRIDE)
PATCHSITE=	sh.wide.ad.jp:/JAPAN/mule/
.else
PATCHSITE=	${MASTER_SITE_OVERRIDE}
.endif
DEPENDS=	${PORTSDIR}/utils/Wnn
PREPATCH_COOKIE=	${.CURDIR}/work/.prepatch_done
PREBUILD_COOKIE=	${.CURDIR}/work/.prebuild_done

pre-fetch:
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@for file in ${PATCHFILES}; do \
		if [ ! -f ${DISTDIR}/$$file ]; then \
			echo ">> Fetching patch $$file from remote site...";  \
			${NCFTP} ${NCFTPFLAGS} ${PATCHSITE}$$file \
				&& mv $$file ${DISTDIR}; \
	    	fi \
	 done

pre-patch:	${PREPATCH_COOKIE}

${PREPATCH_COOKIE}:
	/bin/rm -f ${WRKSRC}/src/unexsunos4.c ${WRKSRC}/src/s/freebsd.h
# I took these two files from emacs-19.28 and added -lcrypt
	cp ${FILESDIR}/unexsunos4.c ${WRKSRC}/src
	cp ${FILESDIR}/freebsd.h ${WRKSRC}/src/s
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
