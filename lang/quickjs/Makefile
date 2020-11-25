# $FreeBSD$

PORTNAME=	quickjs
DISTVERSION=	2020.09.06
CATEGORIES=	lang devel
MASTER_SITES=	https://bellard.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${DISTVERSION:S/./-/g}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Embeddable Javascript interpreter in C

LICENSE=	MIT

USES=		compiler:c11 gmake tar:xz

EXTRA_PATCHES=	${FILESDIR}/extra-${CHOSEN_COMPILER_TYPE}-patch-Makefile

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	@${REINPLACE_CMD} -e 's/%%GCC_DEFAULT%%/${GCC_DEFAULT}/' \
		${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
