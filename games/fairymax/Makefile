# New ports collection makefile for:	fairy-max
# Date created:				22 April 2011
# Whom:					Kalten <kalten@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	fairymax
PORTVERSION=	4.8Q
CATEGORIES=	games
MASTER_SITES=	http://freeheimdall.homeunix.org/files/
DISTNAME=	${PORTNAME}-c7a129e
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=fairymax.git;a=snapshot;h=c7a129ead81286990efb8409f238c48c7109c83b;sf=tgz

MAINTAINER=	kalten@gmx.at
COMMENT=	Chess engine (e.g. xboard) for shatranj, courier chess, ...

DIST_SUBDIR=	${PORTNAME}

PLIST_FILES=	bin/fairymax \
		bin/shamax \
		bin/maxqi \
		${DATADIR_REL}/fmax.ini \
		${DATADIR_REL}/qmax.ini
PLIST_DIRS=	${DATADIR_REL}

MAN6=		fairymax.6
MLINKS=		fairymax.6 shamax.6 \
		fairymax.6 maxqi.6

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ARGS+=	INI_FILE_fmax=${DATADIR}/fmax.ini \
		INI_FILE_qmax=${DATADIR}/qmax.ini

post-patch:
	@${CP} ${WRKSRC}/fairymax.pod ${WRKSRC}/fairymax.pod.ori
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g;s|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/fairymax.pod.ori > ${WRKSRC}/fairymax.pod

post-build:
	@${CP} ${WRKSRC}/fmax.man ${WRKSRC}/fairymax.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fairymax ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/shamax ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/maxqi ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/data/fmax.ini ${DATADIR}/fmax.ini
	${INSTALL_DATA} ${WRKSRC}/data/qmax.ini ${DATADIR}/qmax.ini
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6

.include <bsd.port.mk>
