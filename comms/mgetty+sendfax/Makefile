DISTNAME=	mgetty-0.22
DISTFILES=	mgetty+sendfax-0.22.tar.gz
MASTER_SITES=	ftp://hpsystem2.informatik.tu-muenchen.de/pub/comp/networking/communication/modem/mgetty/
MAKE_FLAGS=	CC=cc spool=/var/spool LDFLAGS=-lutil prefix=${PREFIX} -f
USE_GMAKE=	yes
IS_INTERACTIVE= yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/info
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man4
	@(cd ${WRKSRC}/doc; ${GMAKE} manpages)

.include <bsd.port.mk>
