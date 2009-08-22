# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.9.7
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/AutoGen/AutoGen%20${PORTVERSION} \
		${MASTER_SITE_GNU:S/$/:gnu/}

DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT,gnu

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	The Automated Program Generator

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libguile=yes --with-libxml2=yes --datadir=${PREFIX}/share
USE_LDCONFIG=	yes

MAN1=	autogen.1 autoopts-config.1 columns.1 getdefs.1 xml2ag.1
MAN3=	ao_string_tokenize.3 configFileLoad.3 optionFileLoad.3 \
	optionFindNextValue.3 optionFindValue.3 optionFree.3 \
	optionGetValue.3 optionLoadLine.3 optionNextValue.3 \
	optionProcess.3 optionRestore.3 optionOnlyUsage.3 \
	optionSaveFile.3 optionSaveState.3 optionUnloadNested.3 \
	optionVersion.3 strequate.3 streqvcmp.3 streqvmap.3 strneqvcmp.3 \
	strtransform.3

INFO=	autogen

.include <bsd.port.mk>
