PORTNAME=	zile
DISTVERSION=	2.6.4
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Small emacs-like text editor
WWW=		https://www.gnu.org/software/zile/

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:misc/help2man
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgnuregex.so:devel/libgnuregex

USES=		compiler:c++11-lang gmake gnome localbase:ldflags ncurses perl5 \
		pkgconfig vala:build
USE_GNOME=	glib20
USE_PERL5=	build

GNU_CONFIGURE=	yes

LDFLAGS+=	-lgnuregex

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz
PORTDOCS=	AUTHORS FAQ NEWS dotzile.sample

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
