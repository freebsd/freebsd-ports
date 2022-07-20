PORTNAME=	hcs12mem
PORTVERSION=	1.4.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	mk@capri.pl
COMMENT=	Software to manipulate EEPROM/FLASH memory

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

DOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README
DATS=	mc9s12a32.dat mc9s12a64.dat mc9s12a128.dat \
	mc9s12a256.dat mc9s12a512.dat mc9s12d32.dat \
	mc9s12d64.dat mc9s12d128.dat mc9s12d256.dat \
	mc9s12d512.dat mc9s12c32.dat mc9s12c64.dat \
	mc9s12c96.dat mc9s12c128.dat mc9s12gc16.dat \
	mc9s12gc32.dat mc9s12gc64.dat mc9s12gc96.dat \
	mc9s12gc128.dat mc9s12e32.dat mc9s12e64.dat \
	mc9s12e128.dat mc9s12e256.dat mc9s12h128.dat \
	mc9s12h256.dat mc9s12ne64.dat mc9s12uf32.dat \
	mc9s12xd256.dat mc9s12xd512.dat

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DATS:S,^,${WRKSRC}/target/,} ${STAGEDIR}${DATADIR}/
	${INSTALL_MAN}	${WRKSRC}/doc/*.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
