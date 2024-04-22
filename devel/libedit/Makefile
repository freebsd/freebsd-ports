PORTNAME=	libedit
PORTVERSION=	${EDITVERSION}.${EDITDATE}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	https://thrysoee.dk/editline/
DISTNAME=	${PORTNAME}-${EDITDATE}-${EDITVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line editor library
WWW=		https://thrysoee.dk/editline/

LICENSE=	BSD2CLAUSE

USES=		cpe libtool localbase ncurses pathfix
EDITVERSION=	3.1
EDITDATE=	20230828
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CPE_VENDOR=	libedit_project

CONFLICTS_INSTALL=	editline

post-install:
	${MV} ${STAGEDIR}${PREFIX}/share/man/man3/history.3 ${STAGEDIR}${PREFIX}/share/man/man3/el_history.3

.include <bsd.port.mk>
