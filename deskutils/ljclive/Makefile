# Created by: johans
# $FreeBSD$

PORTNAME=	ljclive
PORTVERSION=	0.4.10
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}
DISTNAME=	clive-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Command line client for posting LiveJournal entries

USES=		iconv
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_search_iconv=${ICONV_LIB}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

CONFLICTS=	*clive-[1-9]*

.include <bsd.port.mk>
