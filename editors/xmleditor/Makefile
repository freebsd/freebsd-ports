# ex:ts=8
# Ports collection makefile for:	xmleditor
# Date created:			Jan 18, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmleditor
PORTVERSION=	0.5.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		intl.4:${PORTSDIR}/devel/gettext \
		xml.5:${PORTSDIR}/textproc/libxml

USE_BISON=	yes
USE_GNOMENG=	yes
USE_GNOME=	glib12 gtk12 libglade
USE_AUTOCONF=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
