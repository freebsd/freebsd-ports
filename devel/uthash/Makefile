# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uthash
PORTVERSION=	1.9.8p2
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	zi@FreeBSD.org
COMMENT=	hash table for C structures

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS

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

do-install:
	@${INSTALL_DATA} ${WRKSRC}/src/utarray.h \
		${WRKSRC}/src/uthash.h \
		${WRKSRC}/src/utlist.h \
		${WRKSRC}/src/utstring.h ${STAGEDIR}${PREFIX}/include/
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
