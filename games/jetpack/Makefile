DISTNAME=	jetpack
DISTFILES=	jetpack.tar.Z
USE_IMAKE=	yes
MASTER_SITES=	ftp://iraun1.ira.uka.de/pub/x11/

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
