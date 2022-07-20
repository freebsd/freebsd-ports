PORTNAME=	hcidump
PORTVERSION=	1.5.1
CATEGORIES=	comms sysutils
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bluetooth traffic dumper, similar to tcpdump

LICENSE=	GPLv2

BROKEN_aarch64=	fails to link: can't create dynamic relocation R_AARCH64_ABS64 against local symbol in readonly segment

USES=		uidfix
WRKSRC=		${WRKDIR}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

CFLAGS+=	-DL2CAP_SOCKET_CHECKED=yes -fPIE

PLIST_FILES=	bin/hcidump man/man1/hcidump.1.gz

.include <bsd.port.mk>
