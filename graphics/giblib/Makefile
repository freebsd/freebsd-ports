# Ports collection makefile for:	giblib
# Date created:				12 Nov 2000
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	giblib
PORTVERSION=	1.2.4
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.linuxbrit.co.uk/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A utility library that includes a wrapper for imlib2

LIB_DEPENDS=	Imlib2.3:${PORTSDIR}/graphics/imlib2

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes

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
