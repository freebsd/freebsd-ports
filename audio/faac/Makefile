# New ports collection makefile for:	faac
# Date created:			Wed May  5 16:38:55 EDT 2004
# Whom:				Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	faac
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	faac

MAINTAINER=	ahze@ahze.net
COMMENT=	FAAC is an AAC audio encoder

NO_PACKAGE=	Distribution in binary form is prohibited

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_AUTOMAKE_VER=15
USE_AUTOHEADER_VER=253
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
USE_REINPLACE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

pre-patch: build-depends

post-patch:
	@${ECHO_CMD} "" >>${WRKSRC}/libfaac/psych.h
	@cd ${WRKSRC}; ${ACLOCAL} -I .; \
		${SETENV} ${SCRIPTS_ENV} ${LIBTOOLIZE} --automake
	@${REINPLACE_CMD} -e 's|$$lt_target|$$host|' \
		${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
