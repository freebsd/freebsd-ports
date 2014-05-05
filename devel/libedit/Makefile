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
EDITDATE=	20140213
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-widec

CPPFLAGS=	-D__weakref_visible=extern

post-patch:
	@${REINPLACE_CMD} -e "s/__weak_reference/__weak_extern/g" ${WRKSRC}/src/vi.c

.include <bsd.port.mk>
