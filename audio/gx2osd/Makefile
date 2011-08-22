# New ports collection makefile for:	py-netstring
# Date created:				04 Nov 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	gx2osd
PORTVERSION=	0.2
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://eclipser.xmms2.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OSD client for XMMS2

LIB_DEPENDS=	xmmsclient++.4:${PORTSDIR}/audio/cpp-xmms2 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		xerces-c.27:${PORTSDIR}/textproc/xerces-c2 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

DEPRECATED=	No more public distfiles

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BZIP2=	yes
USE_PYTHON_BUILD=yes
MAKE_JOBS_SAFE=	yes

MAN1=		gx2osd.1

.include <bsd.port.pre.mk>

.if defined(BATCH) || defined(PACKAGE_BUILDING)
WAF_VERBOSE=	--verbose
.endif

.if defined(MAKE_JOBS_NUMBER)
WAF_JOBS=	--jobs=${MAKE_JOBS_NUMBER}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"/CXXFLAGS/s|= cxxflags|= '${CXXFLAGS}'|" ${WRKSRC}/wscript

do-configure:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} \
		--prefix=${PREFIX} \
		--conf-prefix=${LOCALBASE} \
		--with-mandir=${MANPREFIX}/man configure)

do-build:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} ${WAF_JOBS} build)

do-install:
	@(cd ${WRKSRC} && ./waf ${WAF_VERBOSE} install)

.include <bsd.port.post.mk>
