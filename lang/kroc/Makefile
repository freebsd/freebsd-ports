# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kroc
PORTVERSION=	1.5.r6372
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://ftp.i-scream.org/pub/kroc/ \
		ftp://ftp.i-scream.org/pub/kroc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	The Kent Retargetable occam-pi Compiler

BROKEN=		Fails to build

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

ONLY_FOR_ARCHS=	i386

USES=		pathfix pkgconfig tar:bzip2
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes
USE_GL=		yes
USE_MYSQL=	yes
USE_PYTHON=	yes
USE_SDL=	sdl sound
USE_GNOME=	libxslt
USE_AUTOTOOLS=	autoconf:env automake:env
USE_XORG=	xmu xi
GNU_CONFIGURE=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f -name configure.ac | \
		${XARGS} ${REINPLACE_CMD} '/AM_C_PROTOTYPES/d'

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} \
		${AUTORECONF} -f -i)

regression-test:
	@(cd ${WRKSRC} && ${MAKE_CMD} check)

.include <bsd.port.mk>
