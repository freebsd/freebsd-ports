# New ports collection makefile for:	libhx
# Date created:		2009-06-20
# Whom:			Sylvio Cesar <scjamorim@bsd.com.br>
#
# $FreeBSD$
#

PORTNAME=	libHX
PORTVERSION=	2.7
CATEGORIES=	lang
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	libhx

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	Library C with some additional C++ bindings available

USE_LDCONFIG=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes

PORTDOCS=	libHX_Documentation.pdf

post-build:
	@${REINPLACE_CMD} -e 's|doc src|src|g' ${WRKSRC}/Makefile

post-install:
	(mv ${PREFIX}/lib/pkgconfig/libHX.pc ${PREFIX}/libdata/pkgconfig/libHX.pc)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
