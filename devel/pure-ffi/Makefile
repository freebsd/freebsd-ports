# New ports collection makefile for:	pure-ffi
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-ffi
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to libffi

LIB_DEPENDS+=	pure.7:${PORTSDIR}/lang/pure \
		ffi:${PORTSDIR}/devel/libffi

LICENSE_FILE=	${WRKSRC}/COPYING

USE_GCC=	4.2+
USE_GMAKE=	yes

PLIST_FILES=	lib/pure/ffi.pure \
		lib/pure/ffi.so
MAKE_ARGS+=	prefix=${PREFIX} \
		CPPFLAGS+=-I${LOCALBASE}/include  \
		LDFLAGS+=-L${LOCALBASE}/lib \
		CFLAGS="${CFLAGS}"

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
