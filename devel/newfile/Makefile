# Created by: Miguel Mendez <flynn@energyhq.homeip.net>
# $FreeBSD$

PORTNAME=	newfile
PORTVERSION=	1.0.14
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Tool for creating starter files in various languages

LICENSE=	BSD

USE_RUBY=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	newfile.html

.include <bsd.port.options.mk>

post-configure:
	${REINPLACE_CMD} '282s,$$(pkgdatadir)/newfile.rb,$$(DESTDIR)$$(pkgdatadir)/newfile.rb,' ${WRKSRC}/src/Makefile
	${REINPLACE_CMD} '287s,$$(bindir)/newfile,$$(DESTDIR)$$(bindir)/newfile,' ${WRKSRC}/src/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/newfile.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
