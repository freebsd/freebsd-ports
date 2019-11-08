# $FreeBSD$

PORTNAME=	xml2c
PORTVERSION=	20151019
CATEGORIES=	converters
MASTER_SITES=	http://acme.com/software/xml2c/
DISTNAME=	${PORTNAME}_19Oct2015

MAINTAINER=	neel@neelc.org
COMMENT=	Reads in an XML file and produces equivalent C source code

LICENSE=	BSD2CLAUSE

USES=		gnome
USE_GNOME=	libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/xml2c man/man1/xml2c.1.gz

#MAKEFILE=	/dev/null
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xml2c ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xml2c.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/xml2c.1

.include <bsd.port.mk>
