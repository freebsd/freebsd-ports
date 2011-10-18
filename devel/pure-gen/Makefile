# New ports collection makefile for:	pure-sql3
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-gen
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	A C interface generator for the Pure language

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		hs-language-c>=0.3.2:${PORTSDIR}/devel/hs-language-c
LIB_DEPENDS=	pure.7:${PORTSDIR}/lang/pure

MAN1=		pure-gen.1
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}" mandir=${PREFIX}/man

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
