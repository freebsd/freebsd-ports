# New ports collection makefile for:	icoutils
# Date created:				Sun Jun 12 10:19:46 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icoutils
PORTVERSION=	0.27.0
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_GETTEXT=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		extresso.1 genresscript.1 icotool.1 wrestool.1
PLIST_FILES=	\
		bin/extresso \
		bin/genresscript \
		bin/icotool \
		bin/wrestool

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
