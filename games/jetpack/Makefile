DISTNAME=	jetpack
DISTFILES=	jetpack.tar.Z
USE_IMAKE=	yes
MASTER_SITES=	ftp://qiclab.scn.rain.com/pub/games/
MAKE_FLAGS=	PREFIX=${PREFIX} -f

.include <bsd.port.mk>

install:
	@chown games ${PREFIX}/bin/jetpack
	@chmod u+s ${PREFIX}/bin/jetpack
	@chown games ${PREFIX}/lib/X11/jetpack
	@chmod go+r ${PREFIX}/lib/X11/jetpack/jetpack.lev000
