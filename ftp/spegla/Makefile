# ex:ts=8
# New ports collection makefile for:    spegla
# Date created:         Sun Apr 19 16:17:25 PDT 1998
# Whom:                 Jordan Hubbard <jkh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spegla
PORTVERSION=	1.1p4
PORTREVISION=	3
CATEGORIES=	ftp ipv6
MASTER_SITES=  ftp://subzero.campus.luth.se/pub/spegla/
#              ftp://ftp.luth.se/pub/unix/mirror/

PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20020129-3.diff.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mirror program for FTP sites (written in C)

MANCOMPRESSED=	yes
MAN1=		spegla.1

post-extract:
.for file in engine.c regcomp.c regerror.c regexec.c regfree.c cclass.h cname.h regex.h regex2.h utils.h
	@${CP} ${WRKSRC}/regex/${file} ${WRKSRC}
.endfor

pre-install:
	@${MKDIR} ${PREFIX}/share/examples/spegla

post-install:
	${INSTALL_DATA} ${WRKSRC}/freebsd.org ${PREFIX}/share/examples/spegla
	${INSTALL_DATA} ${WRKSRC}/spegla.conf ${PREFIX}/share/examples/spegla
	${INSTALL_SCRIPT} ${WRKSRC}/spegla.sh ${PREFIX}/share/examples/spegla

.include <bsd.port.mk>
