# New ports collection makefile for:	py-netstring
# Date created:				04 Nov 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gx2osd
PORTVERSION=	0.1
CATEGORIES=	audio
MASTER_SITES=	 http://eclipser.no-ip.org/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	An OSD client for XMMS2

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
				xerces-c.27:${PORTSDIR}/textproc/xerces-c2
BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient++.so:${PORTSDIR}/audio/cpp-xmms2
RUN_DEPENDS=	${LOCALBASE}/lib/libxmmsclient++.so:${PORTSDIR}/audio/cpp-xmms2

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

CFLAGS+=	-I${LOCALBASE}/include
LINKFLAGS+=	${LDFLAGS} -L${LOCALBASE}/lib

MAKE_ENV+=	LINKFAGS="${LINKFLAGS}" WAF_HOME=.

MAN1=	gx2osd.1

.include <bsd.port.pre.mk>

pre-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' ${WRKSRC}/wscript

do-configure:
	-@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf --prefix ${PREFIX} configure
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf --prefix ${PREFIX} configure

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf --prefix ${PREFIX} build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf --prefix ${PREFIX} ${INSTALL_TARGET}

.include <bsd.port.post.mk>
