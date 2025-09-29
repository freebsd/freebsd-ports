PORTNAME=	gtkmmorse
DISTVERSION=	0.9.28
CATEGORIES=	comms education hamradio
MASTER_SITES=	https://cgit.git.savannah.gnu.org/cgit/${PORTNAME}.git/snapshot/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Graphical Morse Code Trainer
WWW=		https://gtkmmorse.nongnu.org/ \
		https://www.nongnu.org/gtkmmorse/

LICENSE=	GPLv2+

LIB_DEPENDS=	libao.so:audio/libao \
		libgconfmm-2.6.so:devel/gconfmm26

USES=		autoreconf compiler:c++11-lang gnome pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	gconf2 gtkmm24

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gtkmmorse \
		share/man/man1/gtkmmorse.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|-ansi||g' -e 's|-pedantic||g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
