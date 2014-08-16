# Created by: Samy Al Bahra <samy@kerneled.org>
# $FreeBSD$

PORTNAME=	elf
PORTVERSION=	0.5.4p1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	linux/reverse-engineering

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline based ELF header analyzer

USES=		gmake readline
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/elf man/man1/elf.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's/gcc/${CC}/g' ${WRKSRC}/src/Makefile.in

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src

.include <bsd.port.mk>
