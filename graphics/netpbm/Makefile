DISTFILES=	netpbm-1mar1994.tar.gz
DISTNAME=	netpbm
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
USE_IMAKE=	yes

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
