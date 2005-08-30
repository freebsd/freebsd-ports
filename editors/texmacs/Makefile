# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0.5
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/targz/ \
		ftp://ftp.texmacs.org/pub/TeXmacs/old-targz/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free WYSIWYG scientific text editor

BUILD_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base

USE_XLIB=	yes
USE_ICONV=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-fastalloc --enable-optimize="${CXXFLAGS}" \
		--with-iconv="${LOCALBASE}"
MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:U}

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|#!/bin/bash|#!/bin/sh|g'
	@${REINPLACE_CMD} -e 's|type -p maxima|which maxima|g' \
		${WRKSRC}/plugins/maxima/bin/maxima_detect

post-install:
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libexec/TeXmacs
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/TeXmacs

.include <bsd.port.mk>
