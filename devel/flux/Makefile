# New ports collection makefile for:	flux
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	flux
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.styx.net/projects/flux/

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/flux/html/img
.for DIR in builds howto ideas reference
	@${MKDIR} ${PREFIX}/share/flux/plain/${DIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/plain/${DIR}/* ${PREFIX}/share/flux/plain/${DIR}/
.endfor
.for DIR in tex xml
	@${MKDIR} ${PREFIX}/share/flux/${DIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/${DIR}/* ${PREFIX}/share/flux/${DIR}/
.endfor
.for DOC in AUTHORS NEWS README TODO
	@${INSTALL_DATA} ${WRKSRC}/${DOC} ${PREFIX}/share/flux/
.endfor
	@${INSTALL_DATA} ${WRKSRC}/doc/html/img/* ${PREFIX}/share/flux/html/img
	@${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${PREFIX}/share/flux/html
	@${INSTALL_DATA} ${WRKSRC}/doc/html/*.css ${PREFIX}/share/flux/html
.endif

.include <bsd.port.mk>
