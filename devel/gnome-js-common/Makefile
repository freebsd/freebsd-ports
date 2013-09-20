# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/gnome-js-common/Makefile,v 1.3 2010/01/01 03:30:52 avl Exp $

PORTNAME=	gnome-js-common
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME JavaScript common modules and tests

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool
USES=		pkgconfig gettext

PORTDOCS=	AUTHORS COPYING INSTALL NEWS README ChangeLog

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|== x|= x|g' \
		${WRKSRC}/configure
.if !defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|$${prefix}/share/doc/gnome_js_common|${DOCSDIR}|' \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|install-gnome_js_commondocDATA ||g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
