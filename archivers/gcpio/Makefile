# $FreeBSD$

PORTNAME=	cpio
PORTVERSION=	2.11
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	g

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	GNU cpio copies files to and from archives

USES=		tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g \
		--disable-silent-rules \
		--with-rmt=/etc/rmt

INFO=		cpio

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} check

.include <bsd.port.mk>
