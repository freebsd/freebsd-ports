# New ports collection makefile for:	hunspell
# Date created:		2011-07-20
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hunspell
PORTVERSION=	1.1
CATEGORIES=	hebrew textproc
MASTER_SITES=	http://hspell.ivrix.org.il/
DISTNAME=	hspell-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Hunspell hebrew dictionnary

BUILD_DEPENDS=	iconv:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-fatverb
USE_GMAKE=	yes
USE_PERL5_BUILD=	yes
ALL_TARGET=	myspell

PLIST_FILES=	share/hunspell/he.aff \
		share/hunspell/he.dic
PLIST_DIRS=	share/hunspell

post-patch:
		@${REINPLACE_CMD} 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/pmerge
do-install:
		@${MKDIR} ${PREFIX}/share/hunspell
		@${INSTALL_DATA} ${WRKSRC}/he.aff \
			${WRKSRC}/he.dic \
			${PREFIX}/share/hunspell/

.include <bsd.port.mk>
