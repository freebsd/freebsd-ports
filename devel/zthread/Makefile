# New ports collection makefile for:	ZThread
# Date created:				23 May 2001
# Whom:					pvh@egenetics.com
#
# $FreeBSD$
#

PORTNAME=	zthread
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cs.buffalo.edu/~crahen/projects/zthread/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ZThread-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org
COMMENT=	A platform-independent object-oriented C++ threading library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html ${EXAMPLESDIR}
.for docfile in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/html/* ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
