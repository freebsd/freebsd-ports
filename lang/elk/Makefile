# New ports collection makefile for:    elk
# Version required:     2.2
# Date created:         08 March 1995
# Whom:                 thomas@ghpc8.ihf.rwth-aachen.de
#

DISTNAME=       elk-2.2
MASTER_SITES=	ftp://ftp.x.org/contrib/devel_tools/
PATCH_STRIP=	-p1

#
# /usr/local/lib/elk is built into the port.
# change it in ${WRKSRC}/config/site if you change it here and vice versa.
#

pre-install:
	@mkdir -p ${PREFIX}/lib/elk

install: build
	@echo "===>  Installing for ${DISTNAME}"
	@${MAKE} ${MAKEFLAGS} pre-install
	@(cd ${WRKSRC}; ${MAKE} PREFIX=${PREFIX} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
	@(cd /usr/local/lib/elk; mv bin/scheme ${PREFIX}/bin; \
	  mkdir -p ${PREFIX}/include/elk; mv include/*.h ${PREFIX}/include/elk; \
	  rmdir bin include)
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}

.include <bsd.port.mk>
