# Ports collection makefile for:	giblib
# Date created:				12 Nov 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	giblib
PORTVERSION=	1.2.4
PORTREVISION=	7
CATEGORIES=	graphics devel
MASTER_SITES=	http://linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility library that includes a wrapper for imlib2

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|: install-docsDATA|:|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
