# Created by: Kalten <kalten@gmx.at>
# $FreeBSD$

PORTNAME=	fairymax
PORTVERSION=	4.8S.6
CATEGORIES=	games
MASTER_SITES=	http://freeheimdall.homeunix.org/files/
DISTNAME=	${PORTNAME}-b6a7fa8
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=fairymax.git;a=snapshot;h=0e4813b1b6dbb8a2a85c5b6a42486cfa52724d68;sf=tgz

MAINTAINER=	kalten@gmx.at
COMMENT=	Chess engine for shatranj, courier chess, and others

CONFLICTS=	fairymax-4.8Q.*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

DIST_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		bin/shamax \
		bin/maxqi \
		man/man6/fairymax.6.gz \
		man/man6/shamax.6.gz \
		man/man6/maxqi.6.gz \
		%%DATADIR%%/fmax.ini \
		%%DATADIR%%/qmax.ini
PLIST_DIRS=	%%DATADIR%%

USES=		gmake perl5
USE_PERL5=	build
MAKE_ARGS+=	INI_F=${DATADIR}/fmax.ini \
		INI_Q=${DATADIR}/qmax.ini

OPTIMIZED_CFLAGS_CFLAGS=	-O2

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g'	\
			-e 's|%%DATADIR%%|${DATADIR}|g'	\
		${WRKSRC}/fairymax.pod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fairymax ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shamax ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/maxqi ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/fmax.ini ${STAGEDIR}${DATADIR}/fmax.ini
	${INSTALL_DATA} ${WRKSRC}/data/qmax.ini ${STAGEDIR}${DATADIR}/qmax.ini
	${INSTALL_MAN} ${WRKSRC}/fmax.man ${STAGEDIR}${MAN6PREFIX}/man/man6/${PORTNAME}.6
	${LN} -s ${MAN6PREFIX}/man/man6/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/shamax.6
	${LN} -s ${MAN6PREFIX}/man/man6/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/maxqi.6

.include <bsd.port.mk>
