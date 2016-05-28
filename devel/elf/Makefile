# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	elf
PORTVERSION=	0.5.4p1
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	PACKETSTORM/linux/reverse-engineering

MAINTAINER=	mokhi64@gmail.com
COMMENT=	Commandline based ELF header analyzer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libedit readline
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/elf man/man1/elf.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/src/Makefile.in

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
