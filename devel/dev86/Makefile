# Created by: Philip Schulz <phs@deadc0.de>
# $FreeBSD$

PORTNAME=	dev86
PORTVERSION=	0.16.20
CATEGORIES=	devel
MASTER_SITES=	http://v3.sk/~lkundrak/dev86/archive/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
DISTNAME=	Dev86src-${PORTVERSION}

MAINTAINER=	phs@deadc0.de
COMMENT=	8086 development tools

CONFLICTS=	bcc-[0-9]* \
		bin86-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
DESTDIRNAME=	DIST

post-patch:
# Respect CFLAGS in Makefiles.
	@${GREP} -Rl 'CFLAGS=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i "" \
	    -Ee "s|CFLAGS='|&${CFLAGS} |; s|^(CFLAGS=)([^'])|\1${CFLAGS} \2|"

.include <bsd.port.mk>
