# New ports collection makefile for:    icon
# Version required:     9.0
# Date created:         05 April 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#
# $Id: Makefile,v 1.3 1995/07/29 09:54:58 asami Exp $
#

DISTNAME=       icon-9.0
DISTFILES=	unix_tar.gz
CATEGORIES+=	lang
MASTER_SITES=	ftp://cs.arizona.edu/icon/packages/unix/

PATCH_STRIP=	-p1
NO_WRKSUBDIR=	true
ALL_TARGET=	Icon

# work around a bug in rtt's preprocessor
#
do-build:
	@(ENABLE_STARTUP_LOCALE=; \
	  unset ENABLE_STARTUP_LOCALE; \
	  cd ${WRKSRC}; \
	  ${MAKE} PREFIX=${PREFIX} X11BASE=${X11BASE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

.include <bsd.port.mk>
