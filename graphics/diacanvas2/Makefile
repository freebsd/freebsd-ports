# ex:ts=8
# Ports collection makefile for:	diacanvas2
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	diacanvas2
PORTVERSION=	0.12.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	diacanvas

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general drawing canvas from dia dialog editor

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

BROKEN=		"Broken pkg-plist"

USE_GNOME=	gnomehack libgnomeprint libgnomeprintui libartlgpl2 \
		libgnomecanvas
USE_PYTHON=	2.2+
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

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
