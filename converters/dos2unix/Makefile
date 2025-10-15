PORTNAME=	dos2unix
DISTVERSION=	7.5.3
CATEGORIES=	converters
MASTER_SITES=	SF \
		https://waterlan.home.xs4all.nl/dos2unix/

MAINTAINER=	dim@FreeBSD.org
COMMENT=	DOS/Mac to Unix and vice versa text file format converter
WWW=		https://waterlan.home.xs4all.nl/dos2unix.html

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.txt

USES=		gmake

MAKE_ARGS=	docsubdir="${PORTNAME}" \
		prefix="${PREFIX}"

CONFLICTS_INSTALL=	unix2dos

OPTIONS_DEFINE=	DOCS MANPAGES NLS
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_MAKE_ARGS_OFF=	ENABLE_NLS=

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dos2unix
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/unix2dos

.include <bsd.port.mk>
