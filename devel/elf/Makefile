PORTNAME=	elf
PORTVERSION=	0.5.4p1
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	PACKETSTORM/linux/reverse-engineering

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline based ELF header analyzer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libedit readline

CPPFLAGS+=	-DWANT_OBSOLETE_TYPEDEFS
GNU_CONFIGURE=	yes
PLIST_FILES=	bin/elf share/man/man1/elf.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC}|g' ${WRKSRC}/src/Makefile.in

do-build:
	${DO_MAKE_BUILD} -C ${WRKSRC}/src

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
