PORTNAME=	catgirl
PORTVERSION=	2.2a
CATEGORIES=	irc
MASTER_SITES=	https://git.causal.agency/catgirl/snapshot/

MAINTAINER=	june@causal.agency
COMMENT=	TLS-only terminal IRC client
WWW=		https://git.causal.agency/catgirl/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler:c++11-lang ncurses pkgconfig

LIB_DEPENDS+=	libtls.so:security/libretls

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${PREFIX}/share/man

PLIST_FILES=	bin/catgirl \
		share/man/man1/catgirl.1.gz

.include <bsd.port.pre.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/catgirl

.include <bsd.port.post.mk>
