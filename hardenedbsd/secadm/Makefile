# $FreeBSD$

PORTNAME=	secadm
PORTVERSION=	0.5
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	HardenedBSD Security Administration

MAKE_JOBS_UNSAFE=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	HardenedBSD
GH_PROJECT=	secadm
GH_TAGNAME=	252ca3f

.if !defined(KMOD)
LIBDIR?=	${PREFIX}/lib
.endif

.include <bsd.port.pre.mk>

.if defined(KMOD)
MAKE_ENV+=	WITHOUT_CLI=YES
.else
MAKE_ENV+=	WITHOUT_KMOD=YES
EXPLICIT_SAFESTACK=	yes

LIB_DEPENDS=	libucl.so:${PORTSDIR}/textproc/libucl
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
LIB_DEPENDS+=	libxo.so:${PORTSDIR}/devel/libxo
.endif

.endif

.include <bsd.port.post.mk>

