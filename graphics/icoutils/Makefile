# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icoutils
PORTVERSION=	0.31.0
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LICENSE=	GPLv3

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls
MAKE_JOBS_SAFE=	yes

MAN1=		icotool.1 wrestool.1
PLIST_FILES=	bin/icotool \
		bin/wrestool

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	RESSCRIPTS
RESSCRIPTS_DESC=	PERL resource scripts

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRESSCRIPTS}
RUN_DEPENDS+=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
USE_PERL5_RUN=	yes
MAN1+=		extresso.1 genresscript.1
PLIST_FILES+=	bin/extresso \
		bin/genresscript
.else
post-patch:
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-Makefile.in \
		${FILESDIR}/extra-patch-configure.ac
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not link on sparc64
.endif

.include <bsd.port.post.mk>
