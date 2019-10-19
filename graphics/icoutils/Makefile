# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icoutils
PORTVERSION=	0.32.3
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase shebangfix tar:bzip2
CONFIGURE_ARGS=	--disable-nls
GNU_CONFIGURE=	yes

SHEBANG_FILES=	extresso/*.in

OPTIONS_DEFINE=	EXTRESSO
OPTIONS_SUB=	yes
EXTRESSO_DESC=	Additional extresso and genresscript programs

EXTRESSO_RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww
EXTRESSO_USES=		perl5
EXTRESSO_USE=		PERL5=run

post-patch-EXTRESSO-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s| extresso||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
