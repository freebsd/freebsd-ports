DISTNAME=	xmris.4.02
USE_IMAKE=	yes
USE_GMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
IS_INTERACTIVE=	yes

pre-install:
	@(cd ${WRKSRC}; ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} install.man)

.include <bsd.port.mk>
