PORTNAME=	scheme48
PORTVERSION=	1.9.2
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.s48.org/${PORTVERSION}/

MAINTAINER=	lichray@gmail.com
COMMENT=	Scheme Underground's implementation of R5RS
WWW=		https://www.s48.org

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

CONFLICTS=	scsh

ALL_TARGET=	enough
USES=		cpe gmake tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CPE_VENDOR=	s48

OPTIONS_DEFINE=	DOCS

DOCS_USES=	tex
DOCS_CONFIGURE_ON=	--docdir="${DOCSDIR}"

PLIST_SUB+=	VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} \
		-e 's/-mthreads/-lpthread/' \
		-e 's/-mt/-lpthread/' \
		-e 's/-munaligned-double//' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} \
		-e '/INSTALL.*COPYING/d' \
		${WRKSRC}/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} \
		-e 's/install-doc$$//' \
		-e 's/go doc$$/go/' \
		${WRKSRC}/Makefile.in

do-test:
	${MAKE} -C ${WRKSRC} check

.include <bsd.port.mk>
