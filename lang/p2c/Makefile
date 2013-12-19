# Created by: jmz
# $FreeBSD$

PORTNAME=	p2c
PORTVERSION=	1.21a
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://darkstar.ist.utl.pt/slackware/slackware_source/d/p2c/ \
		http://www.slackware.at/data/slackware-10.0/source/d/p2c/
DISTFILES=	p2c-1.21alpha2.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pascal to C translator

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/p2c-1.21alpha-07.Dec.93/src

USES=		perl5 shebangfix
SHEBANG_FILES=	p2cc.perl
perl_OLD_CMD=	/bin/perl
ALL_TARGET=	all p2cc

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} p2c \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} p2cc \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_LIB} libp2c.a \
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

.include <bsd.port.mk>
