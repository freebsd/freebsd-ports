# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hfs
DISTVERSION=	0_37
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	LOCAL/jmz
DISTNAME=	${PORTNAME}${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Read Macintosh HFS floppy disks, hard drives, and CD-ROMs

LICENCE=	GPLv2

CONFLICTS=	hfsutils-[0-9]*

USE_GMAKE=	yes
MAKE_ARGS=	CCPLUSPLUS="${CXX} -c" LD="${CXX}" DEBUG="${CFLAGS}" \
		INSTALLPATH="${PREFIX}" MANINSTALLDIR="${MANPREFIX}/man/man1"

MAN1=		hfs.1
PLIST_FILES=	bin/hfs
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/.* ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|Volume::Enumerate|Enumerate|' \
		${WRKSRC}/volume.h

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
