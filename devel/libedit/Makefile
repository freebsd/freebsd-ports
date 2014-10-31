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

USES=		libtool pathfix
EDITVERSION=	3.1
EDITDATE=	20141030
WRKSRC=		${WRKDIR}/${PORTNAME}-20141029-${EDITVERSION}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-widec

.include <bsd.port.mk>
