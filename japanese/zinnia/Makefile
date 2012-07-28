# New ports collection makefile for:	zinnia

# Date created:				15 Aug 2010
# Whom:					Timothy Beyer <beyert@cs.ucr.edu>
#
# $FreeBSD$
#

PORTNAME=	zinnia
PORTVERSION=	0.06
CATEGORIES=	japanese
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Simple, customizable, and portable online hand recognition system

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s!=.*!= ${PREFIX}/libdata/pkgconfig!' \
	${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index-ja.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index-ja.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
