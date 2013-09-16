# Created by: Baptiste Daroussin <bapt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.2
CATEGORIES=	hebrew textproc
MASTER_SITES=	http://hspell.ivrix.org.il/ \
		LOCAL/sunpoet/${PORTNAME}
DISTNAME=	hspell-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hebrew hunspell dictionaries

ALL_TARGET=	hunspell
CONFIGURE_ARGS=	--enable-fatverb
GNU_CONFIGURE=	yes
USE_PERL5=	build
USES=		gmake iconv:build perl5

PLIST_FILES=	%%DATADIR%%/he.aff \
		%%DATADIR%%/he.dic
PLIST_DIRSTRY=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} 's|/usr/bin/perl|${PERL}|g' ${WRKSRC}/pmerge

do-install:
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/he.aff ${WRKSRC}/he.dic ${DATADIR}/

.include <bsd.port.mk>
