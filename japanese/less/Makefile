# New ports collection makefile for:	jless
# Version required:	237
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $Id: Makefile,v 1.1.1.1 1995/03/20 12:48:02 asami Exp $
#
DISTNAME=	jless-237
DISTFILES=	less-237.tar.gz
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/misc/less/
MAINTAINER=	asami@FreeBSD.ORG
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/less-237
PATCHFILES=	less-237-iso2022-patch2.gz less-237-iso2022-patch2.p1.gz
.if !defined(MASTER_SITE_OVERRIDE)
PATCHSITE=	ftp://ftp.aist-nara.ac.jp/pub/misc/less/
.else
PATCHSITE=	${MASTER_SITE_OVERRIDE}
.endif
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
	@echo "===>  Applying ISO-2022 support patch"
	@for file in ${PATCHFILES}; do \
		gzip -c -d ${DISTDIR}/$$file | patch -d ${WRKSRC} -p1 -s; \
	done
	@${TOUCH} ${TOUCH_FLAGS} ${PREPATCH_COOKIE}

pre-build:	${PREBUILD_COOKIE}

${PREBUILD_COOKIE}:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;
	@${TOUCH} ${TOUCH_FLAGS} ${PREBUILD_COOKIE}

.include <bsd.port.mk>
