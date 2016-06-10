# Created by: vazquez@iqm.unicamp.br
# $FreeBSD$

PORTNAME=	fpp
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	NL/fortran/ \
		http://ports.toco-domains.de/
DISTNAME=	fdfpp
EXTRACT_SUFX=	.tgz

MAINTAINER=	tz@FreeBSD.org
COMMENT=	Fortran preprocessor for FORTRAN 77 and Fortran 90 programs

ALL_TARGET=	bsd44

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README fpp_spec fpp_license.ps

PLIST_FILES=	bin/fpp \
		man/man1/fpp.1.gz

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsd44/fpp ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/fpp.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
