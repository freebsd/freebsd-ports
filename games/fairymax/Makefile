# New ports collection Makefile for:	fairymax
# Date created:				22 April 2011
# Whom:					Kalten <kalten@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	fairymax
PORTVERSION=	4.8Q
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://freeheimdall.homeunix.org/files/
DISTNAME=	${PORTNAME}-c7a129e
# http://hgm.nubati.net/cgi-bin/gitweb.cgi?p=fairymax.git;a=snapshot;h=c7a129ead81286990efb8409f238c48c7109c83b;sf=tgz

MAINTAINER=	kalten@gmx.at
COMMENT=	Chess engine for shatranj, courier chess, and others

CONFLICTS=	fairymax-4.8Q.[0-9]* fairymax-4.8Q.[0-9]*_[0-9]*

OPTIONS+=	OCFLAGS "Use optimized compiler flags" on

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

USE_GMAKE=	yes
USE_PERL5_BUILD=yes
MAKE_ARGS+=	INI_FILE_fmax=${DATADIR}/fmax.ini \
		INI_FILE_qmax=${DATADIR}/qmax.ini

.include <bsd.port.options.mk>

.if defined(WITHOUT_OCFLAGS) && !defined(WITH_OCFLAGS)
CFLAGS+=
.else
CFLAGS+=	-O2
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
