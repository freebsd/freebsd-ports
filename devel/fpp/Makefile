# Created by: vazquez@iqm.unicamp.br
# $FreeBSD$

PORTNAME=	fpp
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	NL
MASTER_SITE_SUBDIR=	fortran
DISTNAME=	fdfpp
EXTRACT_SUFX=	.tgz

MAINTAINER=	mexas@bris.ac.uk
COMMENT=	Fortran preprocessor for FORTRAN 77 and Fortran 90 programs

ALL_TARGET=	bsd44
MAN1=		fpp.1

OPTIONS_DEFINE=	DOCS
PORTDOCS=	README fpp_spec fpp_license.ps

PLIST_FILES=	bin/fpp

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bsd44/fpp ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/fpp.1 ${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
