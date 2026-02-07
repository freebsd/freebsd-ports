PORTNAME=	curses
PORTVERSION=	1.4.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsd@jonathanprice.org
COMMENT=	Ruby binding for curses, ncurses and PDCurses
WWW=		https://rubygems.org/gems/curses

LICENSE=	RUBY BSD2CLAUSE
LICENSE_COMB=	dual

USES=		gem ncurses

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
