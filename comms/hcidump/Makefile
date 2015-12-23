# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hcidump
PORTVERSION=	1.5.1
CATEGORIES=	comms sysutils
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bluetooth traffic dumper, similar to tcpdump

LICENSE=	GPLv2

USES=		uidfix
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

CFLAGS+=	-DL2CAP_SOCKET_CHECKED=yes

PLIST_FILES=	bin/hcidump man/man1/hcidump.1.gz

BROKEN_powerpc64=	Does not build on powerpc64

.include <bsd.port.mk>
