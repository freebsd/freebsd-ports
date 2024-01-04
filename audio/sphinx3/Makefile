PORTNAME=	sphinx3
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	SF/cmusphinx/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speech recognition system
WWW=		http://www.speech.cs.cmu.edu/sphinx/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Upstream advises on using audio/pocketsphinx
EXPIRATION_DATE=	2024-01-25

LIB_DEPENDS=	libsphinxbase.so:audio/sphinxbase

USES=		gmake libtool localbase:ldflags pathfix
USE_CSTD=	gnu99
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

MAKE_ENV=	MKDIR="${MKDIR}" \
		OSVERSION=${OSVERSION}
MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libs3decoder.so

.include <bsd.port.mk>
