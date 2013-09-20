# Created by: ijliao
# $FreeBSD$

PORTNAME=	dprog
PORTVERSION=	0.3.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.daimi.au.dk/~mailund/dprog/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A language for specifying dynamic programming algorithms

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	EMACS
OPTIONS_DEFAULT=	EMACS
EMACS_DESC=	Install emacs syntax files

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMACS}
PLIST_SUB+=	EMACS=""
.else
PLIST_SUB+=	EMACS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MEMACS}
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/elisp/*.el ${DATADIR}
.endif

.include <bsd.port.mk>
