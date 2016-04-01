# Created by: Mitsuru Yoshida <mitsuru@riken.go.jp>
# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	4.7
PORTREVISION=	8
CATEGORIES=	japanese print
MASTER_SITES=	GNU

PATCH_SITES=	ftp://jupiter.fsci.fuk.kindai.ac.jp/pub/ptex/utils/ \
		http://www.fsci.fuk.kindai.ac.jp/aftp/pub/ptex/utils/
PATCHFILES=	${DISTNAME}-j.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Typeset Texinfo files for printing. Uses TeX

BROKEN=		unfetchable

RUN_DEPENDS=	ptex:japanese/tex-ptex

USES=		cpe gettext gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=j
CPE_VENDOR=	gnu

MAKE_ARGS=	TEXMF=${PREFIX}/${TEXMFLOCAL}
INSTALL_TARGET=	install install-tex

CFLAGS+=	"-DEUC=1"

PLIST_SUB=	TEXMFLOCAL=${TEXMFLOCAL}
TEXMFLOCAL=	share/texmf-local

.include <bsd.port.mk>
