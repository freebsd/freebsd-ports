# New ports collection makefile for: texinfo
# Date created: 18 Aug 1999
# Whom: Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

PORTNAME=	texinfo
PORTVERSION=	4.7
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

PATCH_SITES=	ftp://jupiter.fsci.fuk.kindai.ac.jp/pub/ptex/utils/ \
		http://www.fsci.fuk.kindai.ac.jp/aftp/pub/ptex/utils/
PATCHFILES=	${DISTNAME}-j.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mitsuru@riken.jp
COMMENT=	Typeset Texinfo files for printing. Uses TeX

RUN_DEPENDS=	ptex:${PORTSDIR}/japanese/ptex-tetex

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=j
INSTALL_TARGET=	install install-tex
CFLAGS+=	"-DEUC=1"
MAKE_ARGS=	TEXMF=${PREFIX}/${TEXMFLOCAL}
PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL}
TEXMFLOCAL=	share/texmf-local

MAN1=		jinfo.1 jinfokey.1 jinstall-info.1 jmakeinfo.1 jtexindex.1 jtexi2dvi.1
MAN5=		jinfo.5 jtexinfo.5

.include <bsd.port.mk>
