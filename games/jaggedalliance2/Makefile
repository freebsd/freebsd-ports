# New ports collection makefile for: Jagged Alliance 2
# Date created:         16 Nov 2006
# Whom:                 Christoph Mallon <christoph.mallon@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ja2
PORTVERSION=	0.12.1
CATEGORIES=	games
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/ \
		http://tron.homeunix.org/ja2/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of "Jagged Alliance 2" using SDL

DISTVERSIONSUFFIX=	-source

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=	amd64 arm i386 pc98
ONLY_FOR_ARCHS_REASON=	Needs a little endian environment
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_SDL=	sdl
MAKE_JOBS_SAFE=	yes
NO_CDROM=	License only permits non-commerical use
NO_PACKAGE=	Language of the datafiles must be hardcoded in the game binary

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

OPTIONS=	DUTCH	"Compile for Dutch version (choose ONE)"	Off \
		ENGLISH	"Compile for English version (choose ONE)"	Off \
		FRENCH	"Compile for French version (choose ONE)"	Off \
		GERMAN	"Compile for German version (choose ONE)"	Off \
		ITALIAN	"Compile for Italian version (choose ONE)"	Off \
		POLISH	"Compile for Polish version (choose ONE)"	Off \
		RUSSIAN	"Compile for Russian version (choose ONE)"	Off \
		RUSSIAN_GOLD "Compile for Russian Gold version (choose ONE)"	Off

.include <bsd.port.pre.mk>

.ifdef WITH_ENGLISH
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
.elifdef WITH_RUSSIAN
MAKE_ARGS+=	LNG=RUSSIAN
.elifdef WITH_RUSSIAN_GOLD
MAKE_ARGS+=	LNG=RUSSIAN_GOLD
.else
IGNORE=	no language has been chosen. Please choose the appropriate language for your game CD
.endif

MAKE_ARGS+=	NO_DEPS=yes # For a single full build dependency calculation is unnecessary

MAKE_ARGS+=	SGPDATADIR=${DATADIR}

MAN6=	ja2.6

post-install:
	@${MKDIR} ${DATADIR}/Data/TILECACHE
	@${CAT} ${PKGMESSAGE}

lowercase:
	@for i in \
		${DATADIR}/Data/*.[Ss][Ll][Ff] \
		${DATADIR}/Data/TILECACHE/*.[Jj][Ss][Dd] \
		${DATADIR}/Data/TILECACHE/*.[Ss][Tt][Ii]; \
	do \
		${MV} -n $$i `${DIRNAME} $$i`/`${BASENAME} $$i | ${TR} '[A-Z]' '[a-z]'`; \
	done

.include <bsd.port.post.mk>
