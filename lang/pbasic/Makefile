# Created by: Julian Stacey <jhs@FreeBSD.org>
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

BROKEN_aarch64=	Fails to link: missing sbrk

ALL_TARGET=	freebsd
MAKEFILE=	makefile
PLIST_FILES=	bin/pbasic man/man1/pbasic.1.gz

post-patch:	.SILENT
	${REINPLACE_CMD} -e '/^CC/s/=/?=/' \
		-e '/^CFLAGS/{s/=/+=/;s/-O//;}' \
		${WRKSRC}/freebsd/makefile
	${ECHO_CMD} '.PHONY: $$(SYSTEMS)' >>${WRKSRC}/makefile

do-configure:
	-cd ${WRKSRC} ; ${RM} -r termio m68000 msdos vax pyramid ns32000 \
			pdp11 cursor/cursor.dos cursor/cursor.ukc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/basic ${STAGEDIR}${PREFIX}/bin/pbasic
	${INSTALL_MAN} ${WRKSRC}/docs/basic.1 ${STAGEDIR}${PREFIX}/man/man1/pbasic.1

.include <bsd.port.mk>
