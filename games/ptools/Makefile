# New ports collection makefile for:	ptools
# Date created:				2008-01-15
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	ptools
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://www.koth.org/pmars/:koth \
		http://www.infionline.net/~wtnewton/corewar/:corestep
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//}.zip:koth \
		pmars08s.zip:koth \
		p3-2.pl:koth \
		corestep.c:corestep
EXTRACT_ONLY=	${DISTFILES:C/:[[:alpha:]]+$//:N*.pl:N*.c}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Accessory programs for pMARS (Core War simulator)

USE_ZIP=	yes
USE_PERL5_RUN=	yes
MAKEFILE=	makefile.ptools
ALL_TARGET=	mopt mts pname
NO_WRKSUBDIR=	yes

MAN6=		ptools-mopt.6 ptools-mts.6

post-build:
	(${ECHO_CMD} "#!${PERL}"; ${CAT} ${DISTDIR}/p3-2.pl) \
		> ${WRKSRC}/p3-2.pl
	${CC} ${CFLAGS} -o ${WRKSRC}/corestep ${DISTDIR}/corestep.c -lm

do-install:
.for f in corestep mopt mts pname
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${PREFIX}/bin/${PORTNAME}-${f}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/p3-2.pl ${PREFIX}/bin/${PORTNAME}-p3-2
.for f in mopt.6 mts.6
	${INSTALL_MAN} ${WRKSRC}/${f} ${MAN6PREFIX}/man/man6/${PORTNAME}-${f}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for f in mopt.doc mts.doc pname.doc readme.ptools
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
