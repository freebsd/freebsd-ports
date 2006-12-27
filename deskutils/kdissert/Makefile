# New ports collection makefile for:	kdissert
# Date created:				2004 06 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdissert
PORTVERSION=	1.0.7
CATEGORIES=	deskutils kde
MASTER_SITES=	http://freehackers.org/~tnagy/kdissert/ \
		http://bsdguru.org/distfiles/

MAINTAINER=	alex@BSDGuru.org
COMMENT=	KDE mindmapping tool

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
USE_KDELIBS_VER=	3
USE_PYTHON_BUILD=	yes
MAKE_ENV=	QTDIR="${QT_PREFIX}" KDEDIR="${KDE_PREFIX}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500035
CXXFLAGS+=	-fpermissive
.endif

.if ${OSVERSION} < 500000
BROKEN=		Does not compile on 4.x
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%LINKFLAGS%%|${PTHREAD_LIBS}|g ; \
		 s|%%CPPFLAGS%%|${PTHREAD_CFLAGS}|g' \
			${WRKSRC}/src/kdissert/wscript_build

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install
	@${STRIP_CMD} ${PREFIX}/bin/kdissert

.include <bsd.port.post.mk>
