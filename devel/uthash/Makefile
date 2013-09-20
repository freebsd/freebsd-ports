# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uthash
PORTVERSION=	1.9.8p2
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	zi@FreeBSD.org
COMMENT=	A hash table for C structures

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes
NO_BUILD=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	troydhanson
GH_COMMIT=	d10c46a
GH_TAGNAME=	${GH_COMMIT}

PORTDOCS=	ChangeLog.txt todo.txt userguide.txt utarray.txt \
		utlist.txt utstring.txt
PLIST_FILES=	include/utarray.h include/uthash.h include/utlist.h \
		include/utstring.h

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/utarray.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/uthash.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/utlist.h ${PREFIX}/include/
	@${INSTALL_DATA} ${WRKSRC}/src/utstring.h ${PREFIX}/include/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
