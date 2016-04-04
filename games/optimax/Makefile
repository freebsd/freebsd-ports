# Created by: alepulver
# $FreeBSD$

PORTNAME=	optimax
PORTVERSION=	0.63
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.corewar.info/optimax/dload/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}_unix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		fsh94nop0.3.zip \
		fsh88.zip \
		fsh94draft01.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Core War optimizer written in Perl

RUN_DEPENDS=	p5-Tk>=0:x11-toolkits/p5-Tk

USES=		perl5 zip
USE_PERL5=	run
WRKSRC=		${WRKDIR}/publish_${PORTVERSION:S/.//}
BUILD_WRKSRC=	${WRKSRC}/optimars/optimars_0.1
ALL_TARGET=	exmars

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -rf ${WRKSRC}/fsh94nop0.2
	@${MV} ${WRKDIR}/fsh* ${WRKDIR}/optimax/fsh* ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|-O6|${CFLAGS} -O3|; s|^CCFLAGS +=.*||' \
		${BUILD_WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -i "" -e 's|^#!/.*|#!${PERL}|' ${WRKSRC}/*.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/opti06_3.pl ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKSRC}/remote.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-remote
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/optimars ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_DATA} ${WRKSRC}/optitools.pm ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${CP} -r *.red fsh* templates phase3.lst tables \
		${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.unix ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
