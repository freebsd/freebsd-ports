# Created by: Kalten <kalten@gmx.at>
# $FreeBSD$

PORTNAME=	fairymax
PORTVERSION=	4.8S.5
CATEGORIES=	games
MASTER_SITES=	http://freeheimdall.homeunix.org/files/
DISTNAME=	${PORTNAME}-b6a7fa8
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=fairymax.git;a=snapshot;h=b6a7fa8ae7c54db7bb5a9415ccae3fd55e9b360e;sf=tgz

MAINTAINER=	kalten@gmx.at
COMMENT=	Chess engine for shatranj, courier chess, and others

CONFLICTS=	fairymax-4.8Q.*

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

DIST_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		bin/shamax \
		bin/maxqi \
		%%DATADIR%%/fmax.ini \
		%%DATADIR%%/qmax.ini
PLIST_DIRS=	%%DATADIR%%

MAN6=		${PORTNAME}.6
MLINKS=		${PORTNAME}.6 shamax.6 \
		${PORTNAME}.6 maxqi.6

USES=		gmake perl5
USE_PERL5=	build
MAKE_ARGS+=	INI_F=${DATADIR}/fmax.ini \
		INI_Q=${DATADIR}/qmax.ini

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O2
.else
CFLAGS+=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g'	\
			-e 's|%%DATADIR%%|${DATADIR}|g'	\
		${WRKSRC}/fairymax.pod

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fairymax ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shamax ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/maxqi ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/fmax.ini ${DATADIR}/fmax.ini
	${INSTALL_DATA} ${WRKSRC}/data/qmax.ini ${DATADIR}/qmax.ini
	${INSTALL_MAN} ${WRKSRC}/fmax.man ${MAN6PREFIX}/man/man6/${MAN6}

.include <bsd.port.mk>
