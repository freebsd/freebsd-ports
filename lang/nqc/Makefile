# Created by: kbyanc
# $FreeBSD$

PORTNAME=	nqc
PORTVERSION=	3.1.r6
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://bricxcc.sourceforge.net/nqc/release/ \
		ftp://ftp2.za.freebsd.org/pub/nqc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for writing programs for the Lego RCX

LICENSE=	MPL10
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake dos2unix tar:tgz
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/nqc man/man1/nqc.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-rcxlib-RCX_USBTowerPipe_fbsd.cpp
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nqc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/nqc-man-2.1r1-0.man \
		${STAGEDIR}${MANPREFIX}/man/man1/nqc.1

.include <bsd.port.post.mk>
