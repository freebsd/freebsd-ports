# New ports collection makefile for:	qhacc
# Date created:		28 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	qhacc
PORTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple QT-based financial manager

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

USE_QT_VER=	3
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--enable-mysql=no \
		--with-qt-moc=${QT_PREFIX}/bin \
		--with-qt-libs=${QT_PREFIX}/lib
INSTALLS_SHLIB=	yes

STRIP=		# none

post-patch:
	@${REINPLACE_CMD} 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/lib/|g ; \
		 s|#! /bin/sh|#!${LOCALBASE}/bin/bash|g' \
			${WRKSRC}/src/qhacc.orig
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-O2 -Wall -g||g ; \
		 s|contrib docs qm|contrib|g ; \
		 s|$$(prefix)/plugins|$$(pkglibdir)/plugins|g'

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/qhacc-*
.for file in accounts memorized preferences transactions
	${INSTALL_DATA} ${WRKSRC}/contrib/easysetup/${file} ${PREFIX}/lib/qhacc
.endfor
	${INSTALL_DATA} ${WRKSRC}/qm/*.qm ${PREFIX}/lib/qhacc
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
