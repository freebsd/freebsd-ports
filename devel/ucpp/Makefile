# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ucpp
PORTVERSION=	1.3.4
CATEGORIES=	devel
MASTER_SITES=	# GITHUB

MAINTAINER=	crees@FreeBSD.org
COMMENT=	C preprocessor and lexer

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	scarabeusiv
USES=		autoreconf libtool pathfix
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} '/^CFLAGS/s/-ansi//' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
