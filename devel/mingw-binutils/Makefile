# New ports collection makefile for: mingw-binutils
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.11.92
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mingw
PKGNAMEPREFIX=	mingw-
DISTNAME=	${PORTNAME}-${PORTVERSION}-20011113-src${EXTRACT_SUFFIX}
DIST_SUBDIR=	mingw

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FSF binutils-2.11.90 for Windows cross-development

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-20011113

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--target=i386-mingw32msvc

MAN1=	i386-mingw32msvc-addr2line.1 \
	i386-mingw32msvc-ar.1        \
	i386-mingw32msvc-as.1        \
	i386-mingw32msvc-dlltool.1   \
	i386-mingw32msvc-c++filt.1   \
	i386-mingw32msvc-ld.1        \
	i386-mingw32msvc-nlmconv.1   \
	i386-mingw32msvc-nm.1        \
	i386-mingw32msvc-objcopy.1   \
	i386-mingw32msvc-objdump.1   \
	i386-mingw32msvc-ranlib.1    \
	i386-mingw32msvc-readelf.1   \
	i386-mingw32msvc-size.1      \
	i386-mingw32msvc-strings.1   \
	i386-mingw32msvc-strip.1     \
	i386-mingw32msvc-windres.1

post-install:
	@for file in \
	  addr2line ar as c++filt dlltool gasp ld nm \
	  objcopy objdump ranlib size strings strip windres; \
	do \
	  ${STRIP_CMD} ${PREFIX}/bin/i386-mingw32msvc-$${file}; \
	done
	@for file in ar as dlltool ld nm ranlib strip; \
	do \
	  ${STRIP_CMD} ${PREFIX}/i386-mingw32msvc/bin/$${file}; \
	done

.include <bsd.port.mk>
