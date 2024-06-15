PORTNAME=	zile
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor
WWW=		https://www.gnu.org/software/zile/

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:misc/help2man
LIB_DEPENDS=	libgc.so:devel/boehm-gc \
		libgee-0.8.so:devel/libgee \
		libgnuregex.so.6:devel/libgnuregex

USES=		compiler:c++11-lang gmake gnome localbase:ldflags  \
		ncurses perl5 pkgconfig
USE_GNOME=	glib20
USE_PERL5=	build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--without-included-regex

LDFLAGS+=	-lgnuregex

PLIST_FILES= bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		%%DOCSDIR%%/AUTHORS \
		%%DOCSDIR%%/dotzile.sample \
		%%DOCSDIR%%/FAQ \
		%%DOCSDIR%%/NEWS

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/need_charset_alias=/s|true|false|g' ${WRKSRC}/lib/Makefile.in
	@${REINPLACE_CMD} -e \
		's|@pkgdatadir@|${DOCSDIR}|' ${WRKSRC}/doc/man-extras

.include <bsd.port.post.mk>
