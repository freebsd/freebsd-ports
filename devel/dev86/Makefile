# Created by: Philip Schulz <phs@deadc0.de>
# $FreeBSD$

PORTNAME=	dev86
PORTVERSION=	0.16.18
CATEGORIES=	devel
MASTER_SITES=	http://www.debath.co.uk/dev86/ \
		http://tmp.chruetertee.ch/ \
		http://disasterarea.chruetertee.ch/
DISTNAME=	Dev86src-${PORTVERSION}

MAINTAINER=	phs@deadc0.de
COMMENT=	Robert de Bath's 8086 development tools

CONFLICTS=	bcc-[0-9]* \
		bin86-[0-9]*

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		as86.1 bcc.1 elks.1 elksemu.1 ld86.1

NO_STAGE=	yes
post-patch:
# Respect CFLAGS in Makefiles.
	@${GREP} -Rl 'CFLAGS=' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -i "" \
	    -Ee "s|CFLAGS='|&${CFLAGS} |; s|^(CFLAGS=)([^'])|\1${CFLAGS} \2|"

.include <bsd.port.mk>
