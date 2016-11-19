# Created by: jmz
# $FreeBSD$

PORTNAME=	p2c
PORTVERSION=	2.01
CATEGORIES=	lang
MASTER_SITES=	https://schneider.ncifcrf.gov/p2c/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pascal to C translator

LICENSE=	GPLv2

WRKSRC_SUBDIR=	src

BROKEN_aarch64=	Fails to link: missing sbrk

USES=		perl5 ncurses shebangfix
SHEBANG_FILES=	p2cc.perl
perl_OLD_CMD=	/bin/perl
USE_PERL5=	run
ALL_TARGET=	all p2cc

pre-build:
	@${RM} ${WRKSRC}/p2c.man.inst

post-build:
	@${LN} -sf p2c.man.inst ${WRKSRC}/p2c.1

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} p2c \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} p2cc \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} libp2c.a \
		${STAGEDIR}${PREFIX}/lib)
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/p2c
	(cd ${WRKSRC} && ${INSTALL_DATA} p2c.h \
		${STAGEDIR}${PREFIX}/include/p2c)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/p2c
	(cd ${WRKSRC} && ${INSTALL_DATA} sys.p2crc \
		${STAGEDIR}${PREFIX}/lib/p2c/p2crc)
.for i in loc.p2crc system.imp system.m2 turbo.imp string.pas
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${PREFIX}/lib/p2c)
.endfor
	(cd ${WRKSRC} && ${INSTALL_MAN} p2c.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)

.include <bsd.port.mk>
