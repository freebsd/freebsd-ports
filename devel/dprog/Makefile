# ex:ts=8
# Ports collection makefile for:	dprog
# Date created:			Apr 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

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

OPTIONS=	EMACS "Install emacs syntax files" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EMACS)
PLIST_SUB+=	EMACS=""
.else
PLIST_SUB+=	EMACS="@comment "
.endif

post-install:
.if !defined(WITHOUT_EMACS)
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/elisp/*.el ${DATADIR}
.endif

.include <bsd.port.post.mk>
