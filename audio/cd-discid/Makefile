PORTNAME=	cd-discid
DISTVERSION=	1.4-14
DISTVERSIONSUFFIX=	-ga69bd89
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Backend utility to retrieve CDDB discid information
WWW=		http://linukz.org/cd-discid.shtml

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	taem

MAKE_ARGS+=	MANDIR=${PREFIX}/share/man/man1

PLIST_FILES=	bin/cd-discid \
		share/man/man1/cd-discid.1.gz

.include <bsd.port.mk>
