# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icoutils
PORTVERSION=	0.31.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		shebangfix tar:bzip2
SHEBANG_FILES=	extresso/*.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/icotool bin/wrestool \
		man/man1/icotool.1.gz man/man1/wrestool.1.gz

OPTIONS_DEFINE=	RESSCRIPTS
RESSCRIPTS_DESC=	Additional resource scripts written in Perl

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRESSCRIPTS}
RUN_DEPENDS+=	p5-libwww>=0:www/p5-libwww
USES+=		perl5
USE_PERL5=	run
PLIST_FILES+=	bin/extresso bin/genresscript \
		man/man1/extresso.1.gz man/man1/genresscript.1.gz
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|extresso||' ${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MRESSCRIPTS}
	@(cd ${WRKSRC}/extresso && ${SETENV} ${MAKE_ENV} ${MAKE} \
		${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.include <bsd.port.mk>
