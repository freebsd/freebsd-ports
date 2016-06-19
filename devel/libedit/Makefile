# Created by: jasone
# $FreeBSD$

PORTNAME=	libedit
PORTVERSION=	${EDITVERSION}.${EDITDATE}
DISTVERSION=	${EDITDATE}-${EDITVERSION}
CATEGORIES=	devel
MASTER_SITES=	http://thrysoee.dk/editline/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Command line editor library

LICENSE=	BSD2CLAUSE

USES=		libtool ncurses pathfix
EDITVERSION=	3.1
EDITDATE=	20160618
WRKSRC=		${WRKDIR}/${PORTNAME}-${EDITDATE}-${EDITVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
MAKE_ENV=	LC_ALL=C
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	editline-*

.include <bsd.port.mk>
