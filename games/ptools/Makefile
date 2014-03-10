# Created by: alepulver
# $FreeBSD$

PORTNAME=	ptools
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.koth.org/pmars/:koth \
		http://www.infionline.net/~wtnewton/corewar/:corestep
PKGNAMESUFFIX=	-game
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//}.zip:koth \
		pmars08s.zip:koth \
		p3-2.pl:koth \
		corestep.c:corestep
EXTRACT_ONLY=	${DISTFILES:C/:[[:alpha:]]+$//:N*.pl:N*.c}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Accessory programs for pMARS (Core War simulator)

USES=		perl5 zip
USE_PERL5=	run
MAKEFILE=	makefile.ptools
ALL_TARGET=	mopt mts pname
NO_WRKSUBDIR=	yes

MAN6=		ptools-mopt.6 ptools-mts.6

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>
post-build:
	(${ECHO_CMD} "#!${PERL}"; ${CAT} ${DISTDIR}/p3-2.pl) \
		> ${WRKSRC}/p3-2.pl
	${CC} ${CFLAGS} -o ${WRKSRC}/corestep ${DISTDIR}/corestep.c -lm

do-install:
.for f in corestep mopt mts pname
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/p3-2.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}-p3-2
.for f in mopt.6 mts.6
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}-${f}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for f in mopt.doc mts.doc pname.doc readme.ptools
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
