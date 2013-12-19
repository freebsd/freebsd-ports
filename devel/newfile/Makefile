# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	newfile
PORTVERSION=	1.0.14
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Tool for creating starter files in various languages

LICENSE=	BSD3CLAUSE

USE_RUBY=	yes
GNU_CONFIGURE=	yes
NO_ARCH=	yes

PORTDOCS=	newfile.html

post-configure:
	${REINPLACE_CMD} '282s,$$(pkgdatadir)/newfile.rb,$$(DESTDIR)$$(pkgdatadir)/newfile.rb,' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} '287s,$$(bindir)/newfile,$$(DESTDIR)$$(bindir)/newfile,' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
