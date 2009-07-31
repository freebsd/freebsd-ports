# New ports collection makefile for:	view3ds
# Date created:				18 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	view3ds
PORTVERSION=	1.0.0
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${PORTNAME}_${PORTVERSION}-9.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple realtime 3DS file previewer based on the Lib3ds Library

LIB_DEPENDS=	3ds-1.3:${PORTSDIR}/graphics/lib3ds

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/view3ds
USE_GL=		glut
USE_QT_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
