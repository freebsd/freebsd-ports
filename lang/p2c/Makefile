DISTNAME=	p2c-1.21alpha-07.Dec.93
DISTFILES=	p2c-1.21alpha2.tar.gz
MASTER_SITES=	ftp://src.doc.ic.ac.uk/gnu/hurd/

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/include/p2c
	@cp ${WRKSRC}/src/p2cc.man ${PREFIX}/man/man1/p2cc.1

.include <bsd.port.mk>

