# ex:ts=8
# New ports collection makefile for:	rlwrap
# Date created:			Aug 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rlwrap
PORTVERSION=	0.12
CATEGORIES=	devel
MASTER_SITES=	http://utopia.knoware.nl/~hlub/uck/rlwrap/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Readline wrapper

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
BROKEN=		"Requires readline 4.2 or newer"
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
ALL_TARGET=	# empty

MAN1=	rlwrap.1

.include <bsd.port.post.mk>
