# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	asl
PORTVERSION=	1.41r8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://john.ccac.rwth-aachen.de/pub/as/source/c_version/
MASTER_SITE_SUBDIR=	devel/lang/assemblers

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Assembler for a variety of microcontrollers/-processors

DEPRECATED=	Unmaintained since 1997
EXPIRATION_DATE=	2014-04-09
ONLY_FOR_ARCHS=	i386 alpha amd64

MAN1=	asl.1 p2bin.1 p2hex.1 pbind.1 plist.1

NO_STAGE=	yes
post-extract:
	${CP} ${FILESDIR}/Makefile.def ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's/mkdirhier/mkdir \-p/' ${WRKSRC}/install.sh

post-install:
	@${MKDIR} ${PREFIX}/share/doc/asl
	${INSTALL_DATA} ${WRKSRC}/doc_EN/* ${PREFIX}/share/doc/asl

.include <bsd.port.mk>
