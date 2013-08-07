# Created by: José García Juanino <jjuanino@gmail.com>
# $FreeBSD$

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.2.0.9
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/xml-copy-editor/${PORTNAME}-linux/${PORTVERSION}

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

LICENSE=	GPLv2

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USES=		gettext
USE_DOS2UNIX=	yes

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	xerces-c.3:${PORTSDIR}/textproc/xerces-c3 \
		xslt:${PORTSDIR}/textproc/libxslt \
		aspell:${PORTSDIR}/textproc/aspell \
		pcre:${PORTSDIR}/devel/pcre \
		xml2:${PORTSDIR}/textproc/libxml2 \
		expat:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_AUTOTOOLS=	libtool
CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${LOCALBASE}/include/libxml2 ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.mk>
