DISTNAME=	jetpack
DISTFILES=	jetpack.tar.Z
USE_IMAKE=	yes
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
MAKE_FLAGS=	PREFIX=${PREFIX} -f

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man6
	@mkdir -p ${PREFIX}/lib/jetpack
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>

install:
	@chown games ${PREFIX}/bin/jetpack
	@chmod u+s ${PREFIX}/bin/jetpack
	@chown games ${PREFIX}/lib/jetpack
	@chmod go+r ${PREFIX}/lib/jetpack/jetpack.lev000
