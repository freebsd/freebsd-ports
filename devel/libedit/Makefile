# Created by: jasone
# $FreeBSD$

PORTNAME=	libedit
PORTVERSION=	${EDITVERSION}.${EDITDATE}
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://thrysoee.dk/editline/
DISTNAME=	${PORTNAME}-${EDITDATE}-${EDITVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line editor library

LICENSE=	BSD2CLAUSE

USES=		libtool ncurses pathfix
EDITVERSION=	3.1
EDITDATE=	20170329
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-widec
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	editline-*

post-install:
	${MV} ${STAGEDIR}${PREFIX}/man/man3/history.3 ${STAGEDIR}${PREFIX}/man/man3/el_history.3

.include <bsd.port.mk>
