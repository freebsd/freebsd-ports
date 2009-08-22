# ex:ts=8
# Ports collection makefile for:	xmleditor
# Date created:			Jan 18, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmleditor
PORTVERSION=	0.5.3
PORTREVISION=	8
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML editor

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	build
USE_GNOME=	gnomehack libglade
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"
USE_LDCONFIG=	yes

# Fix for GCC 4.2
post-patch:
	@${REINPLACE_CMD} -e '257s,((char\*)\*n),n,' \
		-e '/gtk_xml_modules_add_module/s,const ,,' \
		${WRKSRC}/src/gtkxmlmodules.*

.include <bsd.port.mk>
