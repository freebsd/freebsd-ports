#This is pfe Version 0.9.9
#By mr
DISTNAME=	pfe099
DISTFILES=	pfe-0.9.9.tar.gz
MASTER_SITES=	ftp://sunsite.unc.edu/pub/languages/forth/
CATEGORIES+=	languages

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1
	@cp ${WRKSRC}/pfe.1 ${PREFIX}/man/man1/pfe.1

.include <bsd.port.mk>

