# New ports collection makefile for: texinfo
# Version required: 3.12s
# Date created: 18 Aug 1999
# Whom: Mitsuru Yoshida <mitsuru@riken.go.jp>
#
# $FreeBSD$
#

DISTNAME=	texinfo-3.12s
PKGNAME=	ja-texinfo-3.12s
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.cs.umb.edu/private/tex/ \
		ftp://texinfo.org/ \
		ftp://alpha.gnu.org/gnu/gnu/ \
		ftp://ftp.funet.fi/pub/gnu/alpha/

PATCH_SITES=	ftp://jupiter.fsci.fuk.kindai.ac.jp/pub/ptex/utils/ \
		http://www.fsci.fuk.kindai.ac.jp/aftp/pub/ptex/utils/
PATCHFILES=	texinfo-3.12s-j.diff.gz
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
