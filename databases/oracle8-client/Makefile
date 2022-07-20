PORTNAME=	oracle8-client
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	LOCAL/fjoe \
		http://www.grosbein.net/freebsd/distfiles/

MAINTAINER=	bonkor@gmail.com
COMMENT=	Oracle 8 client

USES=		tar:bzip2
ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${PORTNAME}
ORACLE_HOME=	${PREFIX}/${PORTNAME}

do-build:
	@cd ${WRKSRC}/freebsd && ./redefine-syms.sh ../lib/libclntst8.a
	@cd ${WRKSRC}/freebsd && ${MAKE} all patch clean ORACLE_HOME=${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${ORACLE_HOME}
	cd ${WRKSRC} && ${FIND} . -not -name '*.orig' -print0 |\
	    ${CPIO} -dump0 -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${ORACLE_HOME}

.include <bsd.port.mk>
