# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.2.1.3
PORTREVISION=	14
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libxerces-c.so.3:textproc/xerces-c3 \
		libxslt.so:textproc/libxslt \
		libaspell.so:textproc/aspell \
		libpcre.so:devel/pcre \
		libxml2.so:textproc/libxml2 \
		libexpat.so:textproc/expat2

USES=		compiler:c++11-lang dos2unix gettext gmake gnome iconv libtool
USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
USE_GNOME=	intltool
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libxml2
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib ${ICONV_LIB}

.include <bsd.port.mk>
