# New ports collection makefile for:    linux_glide
# Version required:     2.4
# Date created:         Oct, 8, 1998
# Whom:                 cracauer@cons.org "Martin Cracauer"
#
# $Id: Makefile,v 1.6 1998/06/27 05:19:06 asami Exp $
#
#

DISTNAME=	linux_glide_2_4
PKGNAME=	linux_glide-2.4
CATEGORIES=	emulators graphics
MASTER_SITES=	http://www.3dfx.com/software/ \
		ftp://ftp.3dfx.com/pub/glide/

MAINTAINER= 	cracauer@cons.org

PREFIX=		/compat/linux/usr
NO_MTREE=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/Glide2.4

pre-install:
	@[ -d ${PREFIX} ] || ${MKDIR} ${PREFIX}

do-install:
	@zcat ${WRKSRC}/dist.tar.gz | \
		(cd ${PREFIX}; tar fx - lib include bin/test00)
	${MV} ${PREFIX}/bin/test00 ${PREFIX}/bin/test-glide

post-install:
	-/compat/linux/sbin/ldconfig

.include <bsd.port.mk>
