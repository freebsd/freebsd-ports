DISTNAME=	jetpack
DISTFILES=	jetpack.tar.Z
USE_IMAKE=	yes
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/
MAKE_FLAGS=	PREFIX=${PREFIX} -f

.include <bsd.port.mk>

install:
	chown games ${PREFIX}/bin/jetpack
	chmod u+s ${PREFIX}/bin/jetpack
	chown games ${PREFIX}/lib/X11/jetpack
	chmod go+r ${PREFIX}/lib/X11/jetpack/jetpack.lev000
