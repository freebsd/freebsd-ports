# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icoutils
PORTVERSION=	0.32.2
CATEGORIES=	graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert/extract images in Microsoft Windows(R) icon/cursor files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase shebangfix tar:bzip2
SHEBANG_FILES=	extresso/*.in
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

OPTIONS_DEFINE=	RESSCRIPTS
OPTIONS_SUB=	yes

RESSCRIPTS_DESC=	Additional resource scripts written in Perl
RESSCRIPTS_RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww
RESSCRIPTS_USES=	perl5
RESSCRIPTS_USE=		PERL5=run

post-patch-RESSCRIPTS-off:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|extresso||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
