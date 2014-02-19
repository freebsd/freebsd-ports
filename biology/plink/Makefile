# Created by: Jason Bacon <jwbacon@tds.net>
# $FreeBSD$

PORTNAME=	plink
PORTVERSION=	1.07
PORTREVISION=	2
CATEGORIES=	biology science
MASTER_SITES=	http://pngu.mgh.harvard.edu/~purcell/plink/dist/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.zip

MAINTAINER=	jwbacon@tds.net
COMMENT=	Whole genome association analysis toolset

LICENSE=	GPLv2

LIB_DEPENDS=	liblapack.so:${PORTSDIR}/math/lapack

# We need Fortran LDFLAGS to link with Lapack.
USES=		fortran gmake

PLIST_FILES=	bin/plink

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/plink ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
