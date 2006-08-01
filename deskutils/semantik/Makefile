# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	1.0.6
CATEGORIES=	deskutils kde
MASTER_SITES=	http://www.kde-apps.org/content/files/
DISTNAME=	12725-${PORTNAME}-${PORTVERSION}-waf-b

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE mindmapping tool

WRKSRC=		${WRKDIR}/${DISTNAME:S/^12725-//}

USE_BZIP2=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_KDELIBS_VER=	3
USE_PYTHON_BUILD=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}" KDEDIR="${KDE_PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-fpermissive
.endif

post-extract:
	@cd ${WRKSRC} && ${TAR} yxf miniwaf.tar.bz2

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LINKFLAGS%%|${PTHREAD_LIBS}|g ; \
		 s|%%CPPFLAGS%%|${PTHREAD_CFLAGS}|g' \
			${WRKSRC}/src/kdissert/wscript_build

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf.py configure

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf.py

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf.py install
	@${STRIP_CMD} ${PREFIX}/bin/kdissert

.include <bsd.port.post.mk>
