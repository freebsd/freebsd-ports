# ex:ts=8
# Ports collection makefile for:	diacanvas2
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	diacanvas2
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	diacanvas

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general drawing canvas from dia dialog editor

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gnome/__init__.py:${PORTSDIR}/x11-toolkits/py-gnome2

USE_REINPLACE=	yes
USE_PYTHON=	yes
USE_GNOME=	gtk20 libgnomeprintui gnomeprefix gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-gnome-print	# supporting libgnomeprint too old (1.x)
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

#post-patch:
#	@${REINPLACE_CMD} -e "s|gnomeprint-2.0|gnomeprint-2.2|g" \
#		-e "s|gnomeprintui-2.0|gnomeprintui-2.2|g" ${WRKSRC}/configure

.include <bsd.port.mk>
