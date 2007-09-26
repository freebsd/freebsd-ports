# New ports collection makefile for:	thrift
# Date created:	   27 September 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	thrift
PORTVERSION=	20070917
CATEGORIES=	devel
MASTER_SITES=	http://developers.facebook.com/thrift/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Framework for scalable cross-language services development

LIB_DEPENDS=	boost_iostreams:${PORTSDIR}/devel/boost \
		event:${PORTSDIR}/devel/libevent

USE_AUTOTOOLS=	libtool:15
USE_GCC=	4.0+
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-boost=${LOCALBASE} \
		--with-event=${LOCALBASE}
CONFIGURE_ENV+=	${MAKE_ENV}

post-patch:
	${REINPLACE_CMD} -i '' -e 's=lib/py ==' ${WRKSRC}/*.*

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/thrift.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
