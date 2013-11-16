# Created by: Julien Laffaye <kimelto@gmail.com>
# $FreeBSD$

PORTNAME=	re2
PORTVERSION=	20131024
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlaffaye@FreeBSD.org
COMMENT=	Fast C++ regex library

LICENSE=	BSD

MAKE_ARGS=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" prefix=${PREFIX}
USE_LDCONFIG=	yes
USES=		compiler:c++11-lang gmake

WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

post-patch:
# remove tr1 if using libc++
.if ${COMPILER_FEATURES:Mlibc++}
	@${REINPLACE_CMD} -e 's|tr1/||; s|tr1::||' ${WRKSRC}/util/util.h
.endif

post-build:
	@${STRIP_CMD} ${WRKSRC}/obj/so/libre2.so

.include <bsd.port.post.mk>
