# $FreeBSD$

PORTNAME=	secadm
PORTVERSION=	0.5.0
DISTVERSIONPREFIX=	v
PORTREVISION?=	1
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	HardenedBSD Security Administration

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	HardenedBSD
GH_PROJECT=	secadm

.if !defined(KMOD)
LIBDIR?=	${PREFIX}/lib
.endif

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if defined(KMOD)
MAKE_ENV+=	WITHOUT_CLI=YES
.else
MAKE_ENV+=	WITHOUT_KMOD=YES
EXPLICIT_SAFESTACK=	yes

LIB_DEPENDS=	libucl.so:textproc/libucl
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
LIB_DEPENDS+=	libxo.so:devel/libxo
.endif

.endif

.include <bsd.port.post.mk>
