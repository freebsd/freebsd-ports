# Ports collection makefile for:	tardy
# Date created:				Jan 14, 2003
# Whom:					ijliao
#
# $FreeBSD$
#

PORTNAME=	tardy
PORTVERSION=	1.19
CATEGORIES=	archivers
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Manipulate the file headers in tar archive files in various ways

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

MAN1=		tardy.1
PLIST_FILES=	bin/tardy

post-patch:
.for var in CFLAGS LDFLAGS
	@${REINPLACE_CMD} -e 's|^\(${var}\)\ =\ \(.*\)|\1 ?= \2|' \
		${WRKSRC}/Makefile.in
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man1/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
