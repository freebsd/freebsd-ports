PORTNAME=	gtkmmorse
PORTVERSION=	0.9.27
PORTREVISION=	7
CATEGORIES=	comms education hamradio
MASTER_SITES=	SAVANNAH

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Graphical Morse Code Trainer
WWW=		https://www.nongnu.org/gtkmmorse/

DEPRECATED=	Depends on expired devel/gconfmm26
EXPIRATION_DATE=2025-11-25

LIB_DEPENDS=	libao.so:audio/libao \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24 \
		libgconfmm-2.6.so:devel/gconfmm26

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		compiler:c++11-lang pkgconfig tar:bzip2
USE_CXXSTD=	c++11

PLIST_FILES=	bin/gtkmmorse \
		share/man/man1/gtkmmorse.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-ansi||g' -e 's|-pedantic||g' \
		${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
