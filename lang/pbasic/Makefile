# Created by: Julian Stacey <jhs@freebsd.org>
# $FreeBSD$

PORTNAME=	pbasic
PORTVERSION=	2.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.berklix.org/pub/FreeBSD/ports/distfiles/ \
		http://www.berklix.com/~jhs/ftp/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-950813

MAINTAINER=	jhs@berklix.com
COMMENT=	Phil Cockroft's Basic Interpreter (previously Rabbit Basic)
# Ask maintainer if you want newer sources or author's latest e-mail
#  (which is currently "phil@cockcroft.de")

ALL_TARGET=	freebsd
MAKEFILE=	makefile
MAN1=		pbasic.1
PLIST_FILES=	bin/pbasic

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^CC/s/=/?=/' \
		-e '/^CFLAGS/{s/=/+=/;s/-O//;}' \
		${WRKSRC}/freebsd/makefile
	${ECHO_CMD} '.PHONY: $$(SYSTEMS)' >>${WRKSRC}/makefile

do-configure:
	-cd ${WRKSRC} ; ${RM} -rf termio m68000 msdos vax pyramid ns32000 \
			pdp11 cursor/cursor.dos cursor/cursor.ukc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/basic ${PREFIX}/bin/pbasic
	${INSTALL_MAN} ${WRKSRC}/docs/basic.1 ${PREFIX}/man/man1/pbasic.1

.include <bsd.port.mk>
