# New ports collection makefile for:	py-netstring
# Date created:				04 Nov 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gx2osd
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://eclipser.no-ip.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OSD client for XMMS2

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2
BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient++.so.3:${PORTSDIR}/audio/cpp-xmms2
RUN_DEPENDS=	${LOCALBASE}/lib/libxmmsclient++.so.3:${PORTSDIR}/audio/cpp-xmms2

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" WAF_HOME=.

MAN1=		gx2osd.1

.include <bsd.port.pre.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf --conf-prefix=${LOCALBASE} --with-mandir=${PREFIX}/man --prefix=${PREFIX} configure

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf ${INSTALL_TARGET}

.include <bsd.port.post.mk>
