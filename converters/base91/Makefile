# $FreeBSD$

PORTNAME=	base91
PORTVERSION=	0.6.0
CATEGORIES=	converters
MASTER_SITES=	SF/${PORTNAME}/basE91/${PORTVERSION}/

MAINTAINER=	takefu@airport.fm
COMMENT=	Utility to encode and decode base91 files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

# INSTALL_DATA is only used to install documentation related files
MAKE_ENV+=	INSTALL_DATA="${INSTALL_MAN}" INSTALL_PROGRAM="${INSTALL_PROGRAM}"

PLIST_FILES=	bin/b91dec \
		bin/b91enc \
		bin/base91 \
		man/man1/b91dec.1.gz \
		man/man1/b91enc.1.gz \
		man/man1/base91.1.gz

.include <bsd.port.mk>
