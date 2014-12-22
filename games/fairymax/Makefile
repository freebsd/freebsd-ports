# Created by: Kalten <kalten@gmx.at>
# $FreeBSD$

PORTNAME=	fairymax
PORTVERSION=	4.8T
CATEGORIES=	games
MASTER_SITES=	http://freeheimdall.spdns.org/files/
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=fairymax.git;a=snapshot;h=${COMMIT_HASH};sf=tgz
# http://hgm.nubati.net/cgi-bin/gitweb.cgi/fairymax.git/snapshot/${COMMIT_HASH}
# but sha256 changes, as creation date of *.tar inside *.tar.gz changes.
DISTNAME=	${PORTNAME}-${COMMIT_HASH}

MAINTAINER=	kalten@gmx.at
COMMENT=	Chess engine for shatranj, courier chess, and others

CONFLICTS=	fairymax-4.8[QS].*

COMMIT_HASH=	7d6f28c

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

PORTDOCS=	changelog copyright CVfairy.html README

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

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
