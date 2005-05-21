# New ports collection makefile for:	jstrings
# Date created:				29 July 2004
# Whom:					ryo
#
# $FreeBSD$
#

PORTNAME=	jstrings
PORTVERSION=	0.6
CATEGORIES=	japanese
MASTER_SITES=	http://openmya.hacker.jp/hasegawa/jstrings/ \
		http://devel.aquahill.net/ports/jstrings/ \
		http://www.kokone.to/~ryo/lib/ports/jstrings/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.lzh

MAINTAINER=	ryo@aquahill.net
COMMENT=	Japanese enhancement of strings(1) command

EXTRACT_DEPENDS=lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

BROKEN=		Extraction fails

MAN1=		jstrings.1
MANLANG=	ja
PLIST_FILES=	bin/jstrings

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfqw=${WRKDIR}

USE_GMAKE=	yes
MAKEFILE=	makefile.gcc
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" BINDIR="${PREFIX}/bin"
ALL_TARGET=	jstrings

post-extract:
	@${ECHO_MSG} "===>  Converting Kanji code and deleting CR for ${DISTNAME}"
	@(cd ${WRKSRC}; \
	for i in *.c *.h *.txt makefile.* ; \
	do \
		nkf -de $$i > $$i.tmp && ${MV} $$i.tmp $$i; \
	done)

post-install:
	${INSTALL_MAN} ${FILESDIR}/jstrings.1 ${PREFIX}/man/${MANLANG}/man1

.include <bsd.port.mk>
