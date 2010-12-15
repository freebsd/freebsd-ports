# New ports collection makefile for:	texmacs
# Date created:		1 December 2001
# Whom:			Geoffrey Mainland <mainland@apeiron.net>
#
# $FreeBSD$
#

PORTNAME=	texmacs
PORTVERSION=	1.0.7.8
CATEGORIES=	editors print
MASTER_SITES=	ftp://ftp.texmacs.org/pub/TeXmacs/%SUBDIR%/ \
		http://www.predatorlabs.net/dl/
MASTER_SITE_SUBDIR=	targz old-targz
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	rfarmer@predatorlabs.net
COMMENT=	A free WYSIWYG scientific text editor

BUILD_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
		freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	tex:${PORTSDIR}/print/teTeX-base

MAKE_JOBS_SAFE=	yes

USE_PYTHON=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-optimize="${CXXFLAGS}" \
		--with-iconv="${LOCALBASE}"

MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:U}

MAN1=		texmacs.1 fig2ps.1
MANCOMPRESSED=	yes

.if !defined(WITHOUT_IMLIB2)
USE_EFL=	imlib2
CONFIGURE_ARGS+=	--with-imlib2
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "#!/bin/bash" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		 's|#!/bin/bash|#!/bin/sh|g'
	@${FIND} ${WRKSRC} -name \*.bak -delete
	@${REINPLACE_CMD} -e 's|ICONV_LDFLAGS/-liconv|ICONV_LDFLAGS|' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/TeXmacs/misc/mime/texmacs.desktop ${DESKTOPDIR}/
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${PREFIX}/libexec/TeXmacs
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/TeXmacs

.include <bsd.port.post.mk>
