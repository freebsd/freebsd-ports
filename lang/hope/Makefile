# Created by: Lev Serebryakov <lev@serebryakov.spb.ru>
# $FreeBSD$

PORTNAME=	hope
PORTVERSION=	1.1
CATEGORIES=	lang
MASTER_SITES=	http://www.soi.city.ac.uk/~ross/Hope/
DISTNAME=	${PORTNAME}

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Hope is lazy interpreter for HOPE applicative language

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	latex:build
BUILD_DEPENDS+= latex2html:${PORTSDIR}/textproc/latex2html
MAKE_ARGS+=	WITH_DOCS=yes
.endif

USES=		gmake
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
