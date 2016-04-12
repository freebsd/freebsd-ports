# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	fb303
PORTVERSION=	${THRIFT_PORTVERSION}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	APACHE/thrift/${PORTVERSION}
DISTNAME=	thrift-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Facebook Bassline

LICENSE=	APACHE20

LIB_DEPENDS=	libthrift.so:devel/thrift-cpp
BUILD_DEPENDS=	thrift:devel/thrift

ACLOCAL_ARGS=	-I ./aclocal
AUTOMAKE_ARGS=	-a
CONFIGURE_ARGS=	PY_PREFIX="${PREFIX}"
USE_AUTOTOOLS=	autoconf autoheader:env aclocal automake

USES=		compiler gmake perl5 python
USE_PERL5=	run
WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/fb303

PLIST_SUB+=	PORTVERSION="${PORTVERSION}" PYTHON_VER="${PYTHON_VER}"

CONFIGURE_ARGS+=	--without-php

DISTINFO_FILE=	${PORTSDIR}/devel/thrift/distinfo

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == clang
USE_CXXSTD=	c++11
EXTRA_PATCHES+=	${FILESDIR}/extra_patch-cpp__Makefile.am
.endif

post-build:
	(cd ${WRKSRC} && ${LOCALBASE}/bin/thrift --gen perl ${WRKSRC}/if/fb303.thrift)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Facebook/FB303
.for FILE in Constants.pm FacebookService.pm Types.pm
	${INSTALL_DATA} ${WRKSRC}/gen-perl/Facebook/FB303/${FILE} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/Facebook/FB303
.endfor

.include "../thrift/bsd.thrift.mk"
.include <bsd.port.post.mk>
