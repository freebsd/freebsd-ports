# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	1.6.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	apps/editors/emacs/clones zile

MAINTAINER=	ports@freebsd.org

USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

MAN1=		zile.1
MANCOMPRESSED=	no

strip_bins := zile

post-install:
.for bin in ${strip_bins}
	@strip ${PREFIX}/bin/${bin}
.endfor

.include <bsd.port.mk>
