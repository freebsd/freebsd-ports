# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkmmorse
PORTVERSION=	0.9.27
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SAVANNAH

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Graphical Morse Code Trainer

LIB_DEPENDS=	libao.so:audio/libao \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24 \
		libgconfmm-2.6.so:devel/gconfmm26

GNU_CONFIGURE=	yes
USES=		pkgconfig tar:bzip2

PLIST_FILES=	bin/gtkmmorse \
		man/man1/gtkmmorse.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-ansi||g' -e 's|-pedantic||g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
