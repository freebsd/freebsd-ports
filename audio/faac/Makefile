# New ports collection makefile for:	faac
# Date created:			Wed May  5 16:38:55 EDT 2004
# Whom:				Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	faac
PORTVERSION=	1.28
CATEGORIES=	audio
MASTER_SITES=	SFE

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	MPEG-2 and MPEG-4 AAC audio encoder

LIB_DEPENDS=	mp4v2.0:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2

RESTRICTED=	Distribution in binary form is prohibited

USE_BZIP2=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-lmp4v2"
USE_LDCONFIG=	yes

MAN1=		faac.1

.include <bsd.port.pre.mk>

post-patch:
	@${ECHO_CMD} "" >> ${WRKSRC}/libfaac/psych.h

pre-configure:
	@cd ${WRKSRC}; ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake

.include <bsd.port.post.mk>
