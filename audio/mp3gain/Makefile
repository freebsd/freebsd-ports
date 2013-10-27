# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	mp3gain
PORTVERSION=	1.5.2
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\./_/g}-src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A tool to normalize the gain of MP3 files

LICENSE=	LGPL21

NEED_ROOT=	yes

USE_ZIP=	yes
USE_DOS2UNIX=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/mp3gain

post-patch:
	@${CP} ${FILESDIR}/Makefile.main ${WRKSRC}/Makefile
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/mpglibDBL/Makefile

.include <bsd.port.mk>
