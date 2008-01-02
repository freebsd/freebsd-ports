# New ports collection makefile for:   	xmlcopyeditor
# Date created:        			6 December 2007
# Whom:                			José García Juanino <jjuanino@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xmlcopyeditor
PORTVERSION=	1.1.0.3
CATEGORIES=	editors
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=xml-copy-editor

MAINTAINER=	jjuanino@gmail.com
COMMENT=	Fast validating XML editor

USE_WX=		2.8+
WX_COMPS=	wx contrib
WX_CONF_ARGS=	absolute
WX_UNICODE=	yes
USE_GETTEXT=	yes
USE_DOS2UNIX=	src/mynotebook.cpp src/mynotebook.h \
		src/xmlcopyeditor.cpp src/xmlcopyeditor.h
SUB_FILES=	pkg-message

BUILD_DEPENDS+=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS+=	xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

USE_AUTOTOOLS=	autoconf:261 automake:19

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include \
			-I${LOCALBASE}/include/libxml2 ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${PTHREAD_LIBS}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
