# ex:ts=8
# Ports collection makefile for:	diacanvas2
# Date created:			Feb 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	diacanvas2
PORTVERSION=	0.14.4
PORTREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	SF/diacanvas/DiaCanvas2/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A general drawing canvas from dia dialog editor

USE_GNOME=	gnomehack gnometarget pygnome2
USE_PYTHON=	2.2+
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_DISPLAY=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|unit_tests doc|unit_tests|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
