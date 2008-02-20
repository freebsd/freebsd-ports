# New ports collection makefile for:	dev86
# Date created:				25 October 2007
# Whom:					Philip Schulz <phs@deadc0.de>
#
# $FreeBSD$
#

PORTNAME=	dev86
PORTVERSION=	0.16.17
CATEGORIES=	devel
MASTER_SITES=	http://homepage.ntlworld.com/robert.debath/dev86/
DISTNAME=	Dev86src-${PORTVERSION}

MAINTAINER=	phs@deadc0.de
COMMENT=	Robert de Bath's 8086 development tools

CONFLICTS=	bcc-[0-9]* \
		bin86-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		as86.1 bcc.1 elks.1 elksemu.1 ld86.1

post-patch:
# Respect CFLAGS in Makefiles.
	@${GREP} -Rl 'CFLAGS=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i "" \
	    -Ee "s|CFLAGS='|&${CFLAGS} |; s|^(CFLAGS=)([^'])|\1${CFLAGS} \2|"

.include <bsd.port.mk>
