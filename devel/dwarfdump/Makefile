# New ports collection makefile for:	dwarfdump
# Date created:		11 Feb 2005
# Whom:			joerg@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	dwarfdump
PORTVERSION=	20041122
CATEGORIES=	devel
MASTER_SITES=	http://reality.sgi.com/davea/
DISTNAME=	libdwarf-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	A tool to display DWARF debugging information in ELF files

BUILD_DEPENDS=	${LOCALBASE}/lib/libelf.so.0:${PORTSDIR}/devel/libelf \
		${LOCALBASE}/lib/libdwarf.a:${PORTSDIR}/devel/libdwarf
RUN_DEPENDS=	${LOCALBASE}/lib/libelf.so.0:${PORTSDIR}/devel/libelf

WRKSRC=		${WRKDIR}/dwarf-${PORTVERSION}/dwarfdump

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		dwarfdump.1

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/dwarfdump ${PREFIX}/bin
		${INSTALL_DATA} ${WRKSRC}/dwarfdump.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
