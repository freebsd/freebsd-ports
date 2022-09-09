PORTNAME=	qwdtools
CATEGORIES=	games converters
COMMENT=	Convert QuakeWorld demos from QWD format to MVD format
WWW=		https://github.com/deurk/mvdsv
DESCR=		${.CURDIR}/pkg-descr
PKGMESSAGE=	/nonexistent

BUILD_WRKSRC=	${WRKSRC}/tools/qwdtools/source
GH_PROJECT=	mvdsv

CFLAGS+=	-DVERSION_NUMBER=\\\"${PORTVERSION}\\\" \
		-DHOMEPAGE_URL=SERVER_HOME_URL

MASTERDIR=	${.CURDIR}/../mvdsv

.include "${MASTERDIR}/Makefile"
