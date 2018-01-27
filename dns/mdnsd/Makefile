# Created by: Dan Pelleg <daniel+mdnsd@pelleg.org>
# $FreeBSD$

PORTNAME=	mdnsd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7G-107
DISTVERSIONSUFFIX=	-gf4aee59
PORTEPOCH=	1
CATEGORIES=	dns

MAINTAINER=	daniel+mdnsd@pelleg.org
COMMENT=	Advertise a service via Rendezvous

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake:outsource
USE_GITHUB=	yes
GH_ACCOUNT=	Pro

PLIST_FILES=	bin/mdnsd bin/mquery

do-install:
.for f in mdnsd mquery
	${INSTALL_PROGRAM} ${CONFIGURE_WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
