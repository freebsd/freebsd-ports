# ex:ts=8
# Ports collection makefile for:	xmleditor
# Date created:			Jan 18, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmleditor
PORTVERSION=	0.5.3
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML editor

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	yes
USE_GNOME=	gnomehack libglade
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
