# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	1.6.2
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		zile.1
INFO=		zile

post-extract:
	@${RM} -f ${WRKSRC}/doc/zile.info

post-install:
	install-info ${PREFIX}/info/zile.info ${PREFIX}/info/dir

.include <bsd.port.mk>
