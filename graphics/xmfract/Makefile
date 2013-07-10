# Created by: erich@FreeBSD.org
# $FreeBSD$

PORTNAME=	xmfract
PORTVERSION=	1.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	XCONTRIB/graphics
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The dos based 'fractint' with an X/Motif front end

LICENSE=	GPLv2

USES=		motif
USE_AUTOTOOLS=	aclocal autoconf
ACLOCAL_ARGS=	# none
CONFIGURE_ARGS=	--with-editres	\
	--with-motif="motif_includes=${LOCALBASE}/include motif_libraries=${LOCALBASE}/lib"
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		fails to run with: XCreateImage failed
.endif

.include <bsd.port.post.mk>
