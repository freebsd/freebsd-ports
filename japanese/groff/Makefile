# New ports collection makefile for:	jp-groff
# Version required:	1.10+0.99
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.7 1996/11/18 10:23:47 asami Exp $
#

DISTNAME=	groff-1.10
PKGNAME=	jp-groff-0.99
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	graphite@taurus.bekkoame.or.jp

PATCH_SITES=	ftp://ftp.ae.keio.ac.jp/pub/GNU/ \
		ftp://ftp.iij.ad.jp/pub/linux-j/JF/misc/
PATCHFILES=	jgroff-0.99.diff.gz
PATCH_DIST_STRIP=	-p1

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

DNDP=		${WRKSRC}/devnippon/DESC.proto

#for not writing "/usr/local" explicitly in the patch
post-patch:
	/bin/mv -f ${DNDP} ${DNDP}.tmp
	/usr/bin/sed -e '$$d' ${DNDP}.tmp > ${DNDP}
	/bin/echo "postpro ${PREFIX}/bin/grotty" >> ${DNDP}

.include <bsd.port.mk>
