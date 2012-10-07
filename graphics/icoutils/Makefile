# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icoutils
PORTVERSION=	0.30.0
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png
RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

USE_BZIP2=	yes
USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
MAKE_JOBS_SAFE=	yes

MAN1=		extresso.1 genresscript.1 icotool.1 wrestool.1
PLIST_FILES=	bin/extresso \
		bin/genresscript \
		bin/icotool \
		bin/wrestool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
