# New ports collection makefile for: Jagged Alliance 2
# Date created:         16 Nov 2006
# Whom:                 Christoph Mallon <christoph.mallon@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ja2
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/ \
		http://ja2.dragonriders.de/files/

MAINTAINER=	christoph.mallon@gmx.de
COMMENT=	A port of "Jagged Alliance 2" using SDL

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/iconv

DISTVERSIONSUFFIX=	-source

# There are still many endianness and data size issues
# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=	i386
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
NO_CDROM=	License only permits non-commerical use
NO_PACKAGE=	Language of the datafiles must be hardcoded in the game binary

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS=	DUTCH	"Compile for dutch version"	Off \
		ENGLISH	"Compile for english version"	Off \
		FRENCH	"Compile for french version"	Off \
		GERMAN	"Compile for german version"	Off \
		ITALIAN	"Compile for italian version"	Off \
		POLISH	"Compile for polish version"	Off

.include <bsd.port.pre.mk>

.ifndef WITHOUT_ENGLISH
MAKE_ARGS+=	LNG=ENGLISH
.elifdef WITH_DUTCH
MAKE_ARGS+=	LNG=DUTCH
.elifdef WITH_FRENCH
MAKE_ARGS+=	LNG=FRENCH
.elifdef WITH_GERMAN
MAKE_ARGS+=	LNG=GERMAN
.elifdef WITH_ITALIAN
MAKE_ARGS+=	LNG=ITALIAN
.elifdef WITH_POLISH
MAKE_ARGS+=	LNG=POLISH
.else
IGNORE=	no language has been chosen. Please choose the appropriate language for your game CD
.endif

MAKE_ARGS+=	NO_DEPS=yes # For a single full build dependency calculation is unnecessary

MAKE_ARGS+=	DATADIR=${DATADIR}

MAN6=	ja2.6

do-install:
	@${MKDIR} ${DATADIR}/Data/TILECACHE
	@${INSTALL_PROGRAM} ${WRKSRC}/ja ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6

post-install:
	@${SED} -e 's|$${DATADIR}|${DATADIR}|' ${PKGMESSAGE}

lowercase:
	@for i in \
		${DATADIR}/Data/*.[Ss][Ll][Ff] \
		${DATADIR}/Data/TILECACHE/*.[Jj][Ss][Dd] \
		${DATADIR}/Data/TILECACHE/*.[Ss][Tt][Ii]; \
	do \
		${MV} -n $$i `${DIRNAME} $$i`/`${BASENAME} $$i | ${TR} '[A-Z]' '[a-z]'`; \
	done

.include <bsd.port.post.mk>
