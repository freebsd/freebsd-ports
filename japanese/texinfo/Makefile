# New ports collection makefile for: texinfo
# Version required: 4.0
# Date created: 18 Aug 1999
# Whom: Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

DISTNAME=	texinfo-4.0
PKGNAME=	ja-texinfo-4.0
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	texinfo

PATCH_SITES=	ftp://jupiter.fsci.fuk.kindai.ac.jp/pub/ptex/utils/ \
		http://www.fsci.fuk.kindai.ac.jp/aftp/pub/ptex/utils/
PATCHFILES=	texinfo-4.0-j.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mitsuru@riken.go.jp

RUN_DEPENDS=    ptex:${PORTSDIR}/japanese/ptex-euc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=j
INSTALL_TARGET=	install install-tex
CFLAGS+=	"-DEUC=1"
MAKE_ARGS=	TEXMF=${PREFIX}/share/texmf

MAN1=		jinfo.1 jinstall-info.1 jmakeinfo.1 jtexindex.1 jtexi2dvi.1
MAN5=		jinfo.5 jtexinfo.5

.include <bsd.port.mk>
