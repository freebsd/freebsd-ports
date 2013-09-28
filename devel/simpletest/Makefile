# Created by: Roman Neuhauser (<neuhauser@chello.cz>)
# $FreeBSD$

PORTNAME=	simpletest
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}_${PORTVERSION:C/\.0//}
DISTNAME=	${PORTNAME:L}_${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Unit testing, mock objects, and web testing framework for PHP

LICENSE=	LGPL21

USE_PHP=	pcre
USE_PHP_BUILD=	yes
DEFAULT_PHP_VER=5
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:L}

OPTIONS_DEFINE=	DOCS

DOCFILES=	HELP_MY_TESTS_DONT_WORK_ANYMORE README
HTMLDOCFILES=	docs/en/*
DATAFILES=	*.php extensions test LICENSE VERSION

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/ \
	  && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${STAGEDIR}${DATADIR}/{} \; \
	  && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${DATADIR}/{} \;
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
.for file in ${DOCFILES}
	${CP} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor
.for file in ${HTMLDOCFILES}
	${CP} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}/html
.endfor

.include <bsd.port.mk>
