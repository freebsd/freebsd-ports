# Created by: Jordan Hubbard <jkh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spegla
PORTVERSION=	1.1p4
PORTREVISION=	5
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://subzero.campus.luth.se/pub/spegla/ \
		ftp://ftp.luth.se/pub/unix/mirror/

PATCH_SITES=	http://www.mahoroba.org/~ume/ipv6/
PATCHFILES=	${DISTNAME}-ipv6-20020129-3.diff.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	A mirror program for FTP sites (written in C)

MAKE_ARGS=	MANDIR=${MAN1PREFIX}/man/man
PLIST_FILES=	bin/spegla
PORTEXAMPLES=	freebsd.org spegla.conf spegla.sh

MANCOMPRESSED=	yes
MAN1=		spegla.1

OPTIONS_DEFINE=	IPV6 NLS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
post-install:
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} freebsd.org spegla.conf ${EXAMPLESDIR} && \
		${INSTALL_SCRIPT} spegla.sh ${EXAMPLESDIR}
.endif

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	-DINET6
.endif

.include <bsd.port.mk>
