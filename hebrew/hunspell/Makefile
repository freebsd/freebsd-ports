# $FreeBSD$

PORTNAME=	hunspell
PORTVERSION=	1.4
CATEGORIES=	hebrew textproc
MASTER_SITES=	http://hspell.ivrix.org.il/ \
		LOCAL/sunpoet/${PORTNAME}
DISTNAME=	hspell-${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hebrew hunspell dictionaries

LICENSE=	AGPLv3

ALL_TARGET=	hunspell
CONFIGURE_ARGS=	--enable-fatverb
GNU_CONFIGURE=	yes
NO_ARCH=	yes
USE_PERL5=	build
USES=		gmake iconv:build perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/pmerge

PLIST_FILES=	%%DATADIR%%/he.aff \
		%%DATADIR%%/he.dic

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/he.aff ${WRKSRC}/he.dic ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
