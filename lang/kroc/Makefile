# New ports collection makefile for:	kroc
# Date created:				15 January 2006
# Whom:					Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kroc
PORTVERSION=	1.5.r6283
CATEGORIES=	lang
MASTER_SITES=	http://ftp.i-scream.org/pub/kroc/ \
		ftp://ftp.i-scream.org/pub/kroc/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-r/}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	The Kent Retargettable occam-pi Compiler

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GL=		yes
USE_MYSQL=	yes
USE_PYTHON=	yes
USE_SDL=	sdl sound
USE_GNOME=	libxslt
USE_AUTOTOOLS=	autoconf:262:env automake:110:env
USE_XORG=	xmu xi
GNU_CONFIGURE=	yes

MAN1=		kmakef.1 kroc.1 mkoccdeps.1 occ21.1 occamdoc.1
MAN3=		libconvert-inmos.3 libcourse-cycles.3 libcourse-nets.3 \
		libcourse-utils.3 libfile.3 libhostio-inmos.3 libmath-inmos.3 \
		libproc.3 libsock.3 libstreamio-inmos.3 libstring-inmos.3

# Fix pkgconfig location
post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.am" -type f | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} \
		${AUTORECONF} -f -i)

regression-test:
	@cd ${WRKSRC} && ${MAKE} check

.include <bsd.port.mk>
