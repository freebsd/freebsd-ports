# New ports collection makefile for:	faac
# Date created:			Wed May  5 16:38:55 EDT 2004
# Whom:				Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	faac
PORTVERSION=	1.25
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	faac

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder

LIB_DEPENDS=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2

RESTRICTED=	Distribution in binary form is prohibited
WRKSRC=		${WRKDIR}/${PORTNAME}
USE_DOS2UNIX=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	automake:15 autoheader:261 libtool:15
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes
USE_DOS2UNIX=	yes
CONFIGURE_TARGET=--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lmp4v2"

.include <bsd.port.pre.mk>

pre-configure:
	@${ECHO_CMD} "" >>${WRKSRC}/libfaac/psych.h
	@cd ${WRKSRC}; ${SETENV} ${AUTOMAKE_ENV} ${ACLOCAL} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake

.include <bsd.port.post.mk>
