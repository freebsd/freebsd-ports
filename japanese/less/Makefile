# New ports collection makefile for:	jless
# Version required:	237
# Date created:		7 March 1995
# Whom:			Nobuhiro Yasutomi
#
# $Id: Makefile,v 1.3 1995/03/28 06:20:54 asami Exp $
#
DISTNAME=	jless-237
DISTFILES=	less-237.tar.gz
MASTER_SITES=	ftp://ftp.aist-nara.ac.jp/pub/misc/less/
CATEGORIES+=	japanese
MAINTAINER=	asami@FreeBSD.ORG
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/less-237
PATCH_SITES=	ftp://ftp.aist-nara.ac.jp/pub/misc/less/
PATCHFILES=	less-237-iso2022-patch2.gz less-237-iso2022-patch2.p1.gz
PATCH_DIST_STRIP=	-p1
PREBUILD_COOKIE=	${.CURDIR}/work/.prebuild_done

${PREBUILD_COOKIE}:
	find ${WRKSRC} -name \*.orig -exec /bin/rm -f \{} \;
	@${TOUCH} ${TOUCH_FLAGS} ${PREBUILD_COOKIE}

.include <bsd.port.mk>
