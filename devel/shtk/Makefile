PORTNAME=	shtk
PORTVERSION=	1.7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/jmmv/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Application toolkit for POSIX-compliant shell scripts
WWW=		https://github.com/jmmv/shtk/

LICENSE=	BSD3CLAUSE

USES=	pathfix

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS TEST
OPTIONS_DEFAULT=TEST
OPTIONS_SUB=	yes

DOCS_VARS_OFF=	MAKE_FLAGS+=doc_DATA=

post-install-TEST-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/tests

.include <bsd.port.mk>
