# New ports collection makefile for:   vmips
# Date created:        13 July 2004
# Whom:                brg
#
# $FreeBSD$
#

PORTNAME=	vmips
PORTVERSION=	1.2.1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.dgate.org/vmips/releases/vmips-${PORTVERSION}/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	brg@dgate.org
COMMENT=	MIPS R3000 simulator

GNU_CONFIGURE=	yes

MAN1=		vmips.1 vmipstool.1
INFO=		vmips

post-install:
	@${MKDIR} ${PREFIX}/include/vmips
	${INSTALL_DATA} ${WRKSRC}/sample_code/asm_regnames.h \
		${PREFIX}/include/vmips
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/sample_code/ld.script ${DATADIR}

.include <bsd.port.mk>
