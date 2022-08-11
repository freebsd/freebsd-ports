PORTNAME=	scheme48
PORTVERSION=	1.9.2
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.s48.org/${PORTVERSION}/

MAINTAINER=	lichray@gmail.com
COMMENT=	Scheme Underground's implementation of R5RS

LICENSE=	BSD3CLAUSE MIT
LICENSE_COMB=	multi

CONFLICTS=	scsh

ALL_TARGET=	enough
USES=		cpe gmake tar:tgz
GNU_CONFIGURE=	yes
CPE_VENDOR=	s48

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

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
.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	yes
CONFIGURE_ARGS+=--docdir="${DOCSDIR}"
.else
	@${REINPLACE_CMD} \
		-e 's/install-doc$$//' \
		-e 's/go doc$$/go/' \
		${WRKSRC}/Makefile.in
.endif

test:
	${MAKE} -C ${WRKSRC} check

.include <bsd.port.mk>
