# New ports collection makefile for:	libiconv
# Date created:				17 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libiconv
PORTVERSION=	1.13.1
CATEGORIES=	converters devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A character set conversion library

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89
USE_GNOME=	gnometarget
LIBTOOLFILES=	configure libcharset/configure
CONFIGURE_ARGS=	--enable-static \
		--without-libintl-prefix \
		--docdir=${DOCSDIR}
USE_LDCONFIG=	yes
CONFIGURE_ENV=	gl_cv_cc_visibility="no" \
		am_cv_func_iconv="yes" \
		am_cv_proto_iconv_arg1="const"
MAKE_JOBS_UNSAFE=	yes

MAN1=		iconv.1
MAN3=		iconv.3 iconv_open.3 iconv_open_into.3 iconv_close.3 iconvctl.3

OPTIONS=	EXTRA_ENCODINGS	"Include extra character sets" on \
		EXTRA_PATCHES	"Apply patches to fix CP932 add EUCJP-MS" off

.ifdef USE_ICONV
.error USE_ICONV is defined as an environment variable, or in the arguments \
	to "make".  Please unset it and restart the build.
.endif

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EXTRA_ENCODINGS)
CONFIGURE_ARGS+=	--enable-extra-encodings
.endif

.if defined(WITH_EXTRA_PATCHES)
PATCH_SITES+=	http://www2d.biglobe.ne.jp/~msyk/software/libiconv/
PATCH_SITES+=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	nork
PATCHFILES+=	${DISTNAME:C/1\.13\.1/1.13/}-ja-1.patch.gz
PATCH_DIST_STRIP+=	-p1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's:ei_ksc5601:ei_euc_kr:g' ${WRKSRC}/lib/aliases.h

.include <bsd.port.post.mk>
