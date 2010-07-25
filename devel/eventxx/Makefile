# ex:ts=8
# Ports collection makefile for:	eventxx
# Date created:			Apr 9, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	eventxx
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://proj.llucax.com.ar/home/eventxx/releases/ \
		LOCAL/glarkin
MASTER_SITE_SUBDIR=	gahr

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A C++ wrapper for libevent

LIB_DEPENDS=	event-1.4:${PORTSDIR}/devel/libevent

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|-I..|-I.. -I${LOCALBASE}/include -L${LOCALBASE}/lib|g' \
	    ${WRKSRC}/test/Makefile

do-install:
	@${INSTALL_DATA} ${WRKSRC}/eventxx ${PREFIX}/include

post-install:
.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@cd ${WRKSRC}/test && ${COPYTREE_SHARE} \*.cpp ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/test/Makefile ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
