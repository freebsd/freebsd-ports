# Created by: jmacd
# $FreeBSD$

PORTNAME=	scheme48
PORTVERSION=	1.9.2
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.s48.org/${PORTVERSION}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lichray@gmail.com
COMMENT=	The Scheme Underground's implementation of R5RS

LICENSE=	BSD

CONFLICTS=	scsh-[0-9]*

ALL_TARGET=	enough
USES=		gmake
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PLIST_SUB+=	VER=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} \
		-e 's/-mthreads/${PTHREAD_LIBS}/' \
		-e 's/-mt/${PTHREAD_LIBS}/' \
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
