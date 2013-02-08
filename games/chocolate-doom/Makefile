# $FreeBSD$

PORTNAME=	chocolate-doom
PORTVERSION=	1.7.0
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	jakub_lach@mailplus.pl
COMMENT=	Doom port that aims to be compatible with the original exe

LICENSE=	GPLv2

USE_GMAKE=	yes
USE_SDL=	mixer net sdl
USE_PYTHON=	2.5+
MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes

MAN5=		chocolate-doom.cfg.5 default.cfg.5
MAN6=		chocolate-doom.6 chocolate-server.6 chocolate-setup.6
PORTDOCS=	CMDLINE ChangeLog HACKING INSTALL NEWS NOT-BUGS README README.OPL

.include "${.CURDIR}/../doom-data/Makefile.include"

.include <bsd.port.options.mk>

post-patch-script:
	${REINPLACE_CMD} -e 's|gamesdir = $$(prefix)/games|gamesdir = $$(prefix)/bin|' \
		${WRKSRC}/src/Makefile.in ${WRKSRC}/setup/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/HACKING ${DOCSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
