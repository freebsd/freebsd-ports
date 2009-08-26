# New ports collection makefile for:	9base
# Date created:		4 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	9base
DISTVERSION=	b20090309
CATEGORIES=	devel
MASTER_SITES=	http://dl.suckless.org/tools/
DISTNAME=	${PORTNAME}-2

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Port of various original plan9 tools

CFLAGS+=	-I. -c
LDFLAGS+=	-L.
MANPREFIX=	${PREFIX}/9
MAKE_ARGS=	PREFIX="${PREFIX}/9" CC="${CC}" MANPREFIX="${MANPREFIX}/man" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
MAKE_JOB_SAFE=	yes
APPS=		awk basename bc cat cleanname date dc echo grep mk rc sed \
		seq sleep sort tee test touch tr uniq yacc
MAN1=		${APPS:S|$|.1|}
MAN7=		regexp.7

ONLY_FOR_ARCHS=	i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	has low-level code unavailable for ${ARCH}

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX|"${PREFIX}/9"|' ${WRKSRC}/rc/plan9ish.c
	@${REINPLACE_CMD} -e '/OBJTYPE!=/s|!=.*|=${ARCH:S,i386,386,:S,amd64,x86_64,:S,sparc64,sun4u,}|' ${WRKSRC}/lib9/Makefile

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
