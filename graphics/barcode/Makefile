PORTNAME=	barcode
PORTVERSION=	0.98
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	GNU

MAINTAINER=	jev@ecad.org
COMMENT=	Barcode generation library and command-line frontend
WWW=		https://www.gnu.org/software/barcode/

BUILD_DEPENDS=	gawk:lang/gawk

MAKE_ARGS=	INFODIR=${PREFIX}/${INFO_PATH} \
			MAN1DIR=${PREFIX}/share/man/man1 \
			MAN3DIR=${PREFIX}/share/man/man3
GNU_CONFIGURE=	yes
INFO=		barcode

.include <bsd.port.mk>
