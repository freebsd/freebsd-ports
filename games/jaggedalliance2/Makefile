# Created by: Christoph Mallon <christoph.mallon@gmx.de>
# $FreeBSD$

PORTNAME=	ja2
PORTVERSION=	0.12.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://deponie.yamagi.org/freebsd/distfiles/ \
		http://tron.homeunix.org/ja2/

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Port of "Jagged Alliance 2" using SDL

DISTVERSIONSUFFIX=	-source

# Ignore this if you feel adventurous
ONLY_FOR_ARCHS=	amd64 arm i386 pc98
ONLY_FOR_ARCHS_REASON=	Needs a little endian environment
USES=		gmake tar:bzip2
USE_SDL=	sdl
NO_CDROM=	License only permits non-commerical use
NO_PACKAGE=	Language of the datafiles must be hardcoded in the game binary

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
SUB_FILES=	pkg-message

OPTIONS_SINGLE=	LANGUAGE
OPTIONS_SINGLE_LANGUAGE=	DUTCH ENGLISH FRENCH GERMAN ITALIAN POLISH RUSSIAN RUSSIAN_GOLD
OPTIONS_DEFAULT=	ENGLISH

DUTCH_DESC=		Compile for Dutch version
ENGLISH_DESC=		Compile for English version
FRENCH_DESC=		Compile for French version
GERMAN_DESC=		Compile for German version
ITALIAN_DESC=		Compile for Italian version
POLISH_DESC=		Compile for Polish version
RUSSIAN_DESC=		Compile for Russian version
RUSSIAN_GOLD_DESC=	Compile for Russian Gold version

.include <bsd.port.options.mk>

.for i in ${OPTIONS_SINGLE_LANGUAGE}
.  if ${PORT_OPTIONS:M${i}}
MAKE_ARGS+=	LNG=${i}
.  endif
.endfor

MAKE_ARGS+=	NO_DEPS=yes # For a single full build dependency calculation is unnecessary

MAKE_ARGS+=	SGPDATADIR=${STAGEDIR}${DATADIR}

MAKE_ARGS+=	${INSTALL_MACROS:S/BSD_//}

MAKE_ARGS+=	PREFIX=${STAGEDIR}${PREFIX} MANPREFIX=${STAGEDIR}${PREFIX}

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/Data/TILECACHE
	@${CAT} ${PKGMESSAGE}

lowercase:
	@for i in \
		${STAGEDIR}${DATADIR}/Data/*.[Ss][Ll][Ff] \
		${STAGEDIR}${DATADIR}/Data/TILECACHE/*.[Jj][Ss][Dd] \
		${STAGEDIR}${DATADIR}/Data/TILECACHE/*.[Ss][Tt][Ii]; \
	do \
		${MV} -n $$i `${DIRNAME} $$i`/`${BASENAME} $$i | ${TR} '[A-Z]' '[a-z]'`; \
	done

.include <bsd.port.mk>
