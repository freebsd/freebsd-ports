# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.2.0.11
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

LICENSE=	GPLv2

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USES=		gettext iconv dos2unix

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libxerces-c.so.3:${PORTSDIR}/textproc/xerces-c3 \
		libxslt.so:${PORTSDIR}/textproc/libxslt \
		libaspell.so:${PORTSDIR}/textproc/aspell \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libexpat.so:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libxml2 ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS} ${ICONV_LIB}

.include <bsd.port.mk>
