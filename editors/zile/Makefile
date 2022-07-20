PORTNAME=	zile
PORTVERSION=	2.6.2
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

LICENSE=	GPLv3

LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libgnuregex.so.6:devel/libgnuregex \
		libgee-0.8.so:devel/libgee
BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:misc/help2man

USES=		gmake gnome ncurses perl5 pkgconfig compiler:c++11-lang
USE_PERL5=	build
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-regex

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		%%DOCSDIR%%/AUTHORS \
		%%DOCSDIR%%/FAQ \
		%%DOCSDIR%%/NEWS \
		%%DOCSDIR%%/dotzile.sample

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex

post-patch:
	@${REINPLACE_CMD} -e \
		'/need_charset_alias=/s|true|false|g' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@pkgdatadir@|${DOCSDIR}|' ${WRKSRC}/doc/man-extras

.include <bsd.port.mk>
