# Created by: Jordan Hubbard <jkh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spegla
PORTVERSION=	1.1p4
PORTREVISION=	6
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/spegla/ \
		ftp://ftp.luth.se/pub/unix/mirror/

PATCH_SITES=	http://www.mahoroba.org/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20020129-3.diff.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Mirror program for FTP sites (written in C)

BROKEN=		Checksum mismatch
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USES=		uidfix
MAKE_ARGS=	MANDIR=${MAN1PREFIX}/man/man
PLIST_FILES=	bin/spegla man/man1/spegla.1.gz
PORTEXAMPLES=	freebsd.org spegla.conf spegla.sh

OPTIONS_DEFINE=	IPV6
OPTIONS_DEFAULT=IPV6
IPV6_MAKE_ARGS=	-DINET6

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/freebsd.org ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/spegla.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/spegla.sh ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
