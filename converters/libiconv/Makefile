# New ports collection makefile for:	libiconv
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiconv
PORTVERSION=	1.9.1
PORTREVISION=	3
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A character set conversion library

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GNOME=	gnometarget
LIBTOOLFILES=	configure libcharset/configure
CONFIGURE_ARGS=	--enable-static \
		--without-libintl-prefix
INSTALLS_SHLIB=	yes

MAN1=		iconv.1
MAN3=		iconv.3 iconv_open.3 iconv_close.3

.ifdef USE_ICONV
.error USE_ICONV is defined as an environment variable, or in the arguments \
	to "make".  Please unset it and restart the build.
.endif

.if !defined(WITHOUT_EXTRA_ENCODINGS)
CONFIGURE_ARGS+=	--enable-extra-encodings
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "libiconv has the following tunable option(s):"
	@${ECHO_MSG} "	WITHOUT_EXTRA_ENCODINGS=yes	Disable extra character sets"
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's:ei_ksc5601:ei_euc_kr:g' ${WRKSRC}/lib/aliases.h

.include <bsd.port.mk>
