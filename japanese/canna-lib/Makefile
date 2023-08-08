PORTNAME=	canna
PORTVERSION=	3.7p3
PORTREVISION=	9
CATEGORIES=	japanese
MASTER_SITES=	OSDN/canna
PKGNAMESUFFIX=	-lib
DISTNAME=	Canna${PORTVERSION:S/.//g}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Kana-to-Kanji conversion system, library part
WWW=		http://canna.sourceforge.jp/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		imake:notall,noman tar:bzip2
USE_LDCONFIG=	yes
ALL_TARGET=	canna
INSTALL_TARGET=	instsgs
MAKE_JOBS_UNSAFE=	yes
MAKE_ARGS+=	CCOPTIONS="-Wno-error=int-conversion"

.include <bsd.port.mk>
