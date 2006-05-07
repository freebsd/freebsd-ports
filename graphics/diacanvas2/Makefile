# ex:ts=8
# Ports collection makefile for:	diacanvas2
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	diacanvas2
PORTVERSION=	0.14.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	diacanvas

MAINTAINER=	rehsack@liwing.de
COMMENT=	A general drawing canvas from dia dialog editor

USE_GNOME=	gnomehack gnometarget pygnome2
USE_PYTHON=	2.2+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
.if defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	Xvfb:${X_VFBSERVER_PORT} \
		${X11BASE}/lib/X11/fonts/misc/8x13O.pcf.gz:${X_FONTS_MISC_PORT}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|unit_tests doc|unit_tests|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ref/html/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/ref/html/*.png ${DOCSDIR}
.endif

.include <bsd.port.mk>
