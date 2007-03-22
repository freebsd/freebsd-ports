# New ports collection makefile for:	9base
# Date created:		4 March 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	9base
DISTVERSION=	b20060209
CATEGORIES=	devel
MASTER_SITES=	CSME
#http://www.suckless.org/cgi-bin/hgwebdir.cgi/9base/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Port of various original plan9 tools

USE_BZIP2=	yes
CFLAGS+=	-I. -c
LDFLAGS+=	-L.
MANPREFIX=	${PREFIX}/9
MAKE_ARGS=	PREFIX="${PREFIX}/9" CC="${CC}" MANPREFIX="${MANPREFIX}/man" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
APPS=	awk basename bc cat cleanname date dc echo grep ls mk rc read sed seq\
	sleep sort tee test touch tr uniq yacc
#MAN1=	${APPS:S|$|.1|}
PLIST_FILES=	${APPS:S|^|9/bin/|} ${APPS:S|^|9/man/man1/|:S|$|.1|} 9/man/man7/regexp.7 9/etc/rcmain
PLIST_DIRS=	9/bin 9/etc 9/man/man1 9/man/man7 9/man 9

ONLY_FOR_ARCHS=	i386 amd64 sparc64
ONLY_FOR_ARCHS_REASON=	has low-level code unavailable for ${ARCH}

post-patch:
	@${REINPLACE_CMD} -e 's|PREFIX|"${PREFIX}/9"|' ${WRKSRC}/rc/plan9ish.c
	@${REINPLACE_CMD} -e '/OBJTYPE!=/s|!=.*|=${ARCH:S,i386,386,:S,amd64,x86_64,:S,sparc64,sun4u,}|' ${WRKSRC}/lib9/Makefile

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
