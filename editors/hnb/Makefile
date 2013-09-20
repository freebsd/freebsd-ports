# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	hnb
PORTVERSION=	1.9.17
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Hierarchical NoteBook a data organizer

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_GMAKE=	yes
ALL_TARGET=
MAKE_JOBS_UNSAFE=	yes

MAN1=		hnb.1

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} != "i386"
BROKEN=		segfaults on 64bit systems
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS+=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CFLAGS/d' ${WRKSRC}/libcli/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hnb ${PREFIX}/bin
	${INSTALL_MAN}	${WRKSRC}/../doc/hnb.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for FILE in Documentation.hnb Documentation.html hnbrc
	${INSTALL_DATA} ${WRKSRC}/../doc/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
