# New ports collection makefile for:	de-hyphen
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hyphen
PORTVERSION=	2007.02.17
CATEGORIES=	german textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	hyph_de_DE

MAINTAINER=	office@FreeBSD.org
COMMENT=	German hyphenation rules

LICENSE=	LGPL21

USE_ZIP=	yes
NO_BUILD=	yes

DEALIASES=	de_AT de_BE de_CH de_LI de_LU

PLIST_FILES=	share/hyphen/hyph_de_DE.dic
.for ALIAS in ${DEALIASES}
PLIST_FILES+=	share/hyphen/hyph_${ALIAS}.dic
.endfor
PLIST_DIRS=	share/hyphen

do-install:
	@${MKDIR} ${PREFIX}/share/hyphen
	@${INSTALL_DATA} ${WRKDIR}/hyph_de_DE.dic ${PREFIX}/share/hyphen
	@cd ${PREFIX}/share/hyphen; \
	for alias in ${DEALIASES}; do \
	  ${LN} -s hyph_de_DE.dic hyph_$${alias}.dic ; \
	done

.include <bsd.port.mk>
