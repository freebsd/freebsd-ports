DISTNAME=	xmris.4.02
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/R5contrib/

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
