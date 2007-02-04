# New ports collection makefile for:		cacao
# Date created:					2005-04-28
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	cacao
PORTVERSION=	0.97
CATEGORIES=	java devel
MASTER_SITES=	http://www.complang.tuwien.ac.at/cacaojvm/download/cacao-${PORTVERSION}/

MAINTAINER=	arved@FreeBSD.org
COMMENT=	JIT compiler for JAVA

BUILD_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath

USE_AUTOTOOLS=	libltdl
USE_JAVA=	yes
JAVA_VERSION=	1.4+
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-classpath-prefix=${LOCALBASE}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
IGNORE=		unsupported architecture
.endif

.include <bsd.port.post.mk>
